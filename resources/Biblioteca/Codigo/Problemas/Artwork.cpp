// Artwork
//
// Grade n x m com k circulos (obstaculos). Determina se e possivel ir de
// (0,0) ate (n,m) sem tocar nenhum circulo.
// Usa DSU para unir circulos que se tocam/sobrepoem; cada componente guarda
// quais bordas do retangulo toca (esquerda/direita/baixo/cima). O caminho
// fica bloqueado se algum componente tocar duas bordas que fecham um dos
// cantos (0,0) ou (n,m), ou que atravessam de um lado ao outro.
//
// Complexidades:
// O(k^2) para unir os circulos + O(k) para checar bloqueio

int n, m, k; 
struct DSU{
    int n;
    vector<int> p;
    vector<int> r;
    vector<vector<int>> encosta;
    DSU(int _n, vector<vector<int>> _marcador){
        n = _n;
        p.resize(n);
        r.resize(n);
        encosta = _marcador;
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }
    int find(int x){
        return (p[x] == x? x : p[x] = find(p[x]));
    }
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a] += r[b];
            p[b] = a;
            for(int i = 0; i < 4; i++){
                encosta[a][i] |= encosta[b][i];
            }
        }else{
            r[b] += r[a];
            p[a] = b;
            for(int i = 0; i < 4; i++){
                encosta[b][i] |= encosta[a][i];
            }
        }
    }
};
int dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
signed main(){
    fastio;
    cin >> n >> m >> k;
    int pos = 1;
    vector<tuple<int, int, int>> v;
    vector<vector<int>> marcador(k, vector<int>(4, 0));
    for(int i = 0; i < k; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
        if(a-c <= 0) marcador[i][0] = 1;
        if(a+c >= n) marcador[i][1] = 1;
        if(b-c <= 0) marcador[i][2] = 1;
        if(b+c >= m) marcador[i][3] = 1;
    }

    DSU dsu(k, marcador);
    for(int i = 0; i < k; i++){
        auto [x1, y1, r1] = v[i];
        for(int j = i+1; j < k; j++){
            if(j == i) continue;
            auto [x2, y2, r2] = v[j];
            if(dist(x1, y1, x2, y2) <= (r1 + r2)*(r1+r2)){
                dsu.unite(i, j);
            }
        }
    }

    for(int i = 0; i < k; i++){
        auto p = dsu.find(i);
        if(dsu.encosta[p][0] && dsu.encosta[p][1]){
            pos = 0;
            break;
        }if(dsu.encosta[p][2] && dsu.encosta[p][3]){
            pos = 0;
            break;
        }
        if(dsu.encosta[p][0] && dsu.encosta[p][2]){
            pos = 0;
            break;
        }
        if(dsu.encosta[p][1] && dsu.encosta[p][3]){
            pos = 0;
            break;
        }
    }
    if(pos) cout << "S\n";
    else cout << "N\n";
}