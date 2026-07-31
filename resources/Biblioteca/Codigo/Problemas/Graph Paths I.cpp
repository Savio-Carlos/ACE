// Graph Paths I
//
// Conta o numero de caminhos (sequencias de arestas, com repeticao) de
// tamanho exatamente k entre o vertice 0 e o vertice n-1 num grafo
// dirigido. Monta a matriz de adjacencia (multiplicidade de arestas) e
// eleva a potencia k por exponenciacao de matriz (soma/produto padrao,
// ver Primitivas/Matrix.cpp); mt[0][n-1] apos mt^k e a resposta.
//
// Complexidades:
// O(n^3 log k)
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> con(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        con[--a][--b]++;
    }
    matrix mt(con);
    
    mt = mt^k;
    cout << mt[0][n-1] << endl;
}