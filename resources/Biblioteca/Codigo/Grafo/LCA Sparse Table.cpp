// LCA - Sparse Table (Euler Tour + RMQ)
//
// Faz um euler tour da arvore (guardando a depth de cada visita) e usa uma
// sparse table para achar o no de menor depth no intervalo do tour entre a e b (RMQ estatico)
//
// Complexidades:
// build (dfs + buildtable) - O(n log(n))
// query / lca - O(1)
//
// grafo global graph (0-indexado); chamar dfs(root, root) e depois buildtable()
// posso pensar em otimizar como chamo o lca guardando a ultima vez que o no foi chamado
// main() abaixo eh um exemplo completo de uso (le a arvore e responde queries)

int n, timer = 0, tin[MAX], depth[MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<vector<int>> graph; //0 indexado

void dfs(int v, int p){
    tin[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            depth[u] = depth[v]+1;
            dfs(u,v);
            et.push_back(v);
        }
    }
}

void buildtable(){
    for (int i = 0; i < (int)et.size(); i++){
        sp[i][0] = {depth[et[i]], et[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)et.size(); i++){
            sp[i][j] = min (sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pair<int,int> query (int a, int b){
    int len =  b - a + 1;
    int lg = 31 - __builtin_clz(len);
    return min(sp[a][lg], sp[b - (1<<lg) + 1][lg]);
}

int lca(int a, int b){
    if (tin[a] > tin[b]) swap(a,b);
    return query(tin[a], tin[b]).second;
}

signed main() {
    winton;
    int q;
    cin >> n >> q;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,0);
    buildtable();
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        int mac = lca(a,b);
        cout << depth[a] + depth[b] - 2*depth[mac] << endl;
    }

}
