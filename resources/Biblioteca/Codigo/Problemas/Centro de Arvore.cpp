// Centro de Árvore
//
// Acha o(s) centro(s) de uma arvore (vertice(s) que minimizam a maior
// distancia ate qualquer outro vertice), via dupla BFS/DFS do diametro:
// acha um extremo do diametro a partir de um vertice qualquer, acha o
// outro extremo b a partir dele, e o(s) centro(s) sao os vertices cuja
// soma das distancias ate os dois extremos e igual ao diametro (1 ou 2
// vertices).
//
// Complexidades:
// O(n)

vector<vector<int>> graph;
int n, dist[3][MAX];

void dfs(int v, int p, int id){
    for (auto u : graph[v]){
        if (u == p || dist[id][u] > 0) continue;
        dist[id][u] = dist[id][v] + 1;
        dfs(u,v,id);
    }
}
int distance(int id){
    int u = -1, mx = 0;
    for (int i = 1; i <= n; i++){
        if (dist[id][i] > mx){
            u = i;
            mx = dist[id][i];
        }
    }
    return u;
}
int cont(int v, int p, int d){
    if (d == 0) return 1;
    int cur = 0;
    for (auto u : graph[v]){
        if (u == p) continue;
        cur += cont(u,v,d-1);
    }
    return cur;
}

signed main () {
    winton;
    cin >> n;
    graph.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0,0);
    int a = distance(0);
    dfs(a,0,1);
    int b = distance(1);
    dfs(b,0,2);

    vector<int> center;
    for (int i = 1; i <= n; i++){
        if (dist[1][i] + dist[2][i] == dist[1][b] && abs(dist[1][i] - dist[2][i]) <= 1){
            center.push_back(i);
        }
    }
}