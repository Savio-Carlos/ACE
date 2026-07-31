// Graph Paths II
//
// Acha o menor custo de um caminho com exatamente k arestas do vertice 0
// ao vertice n-1 num grafo dirigido ponderado (-1 se inalcancavel).
// Precisa da variante (min, +) da exponenciacao de matriz — troca a soma
// por minimo e o produto por soma no operator* (ver Primitivas/Matrix.cpp,
// que por padrao usa soma/produto normais mod MOD, nao min-plus).
//
// Complexidades:
// O(n^3 log k)
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> con(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        con[a][b] = min(c, con[a][b]);
    }
    matrix mt(con);
    mt = mt^k; 
    int ans = mt[0][n-1];
    if (ans == INF) cout << "-1" << endl;
    else cout << ans << endl;

}