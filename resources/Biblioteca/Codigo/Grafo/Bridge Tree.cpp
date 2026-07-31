// Bridge Tree
//
// Acha as pontes (bridges) do grafo com Tarjan (low-link) e agrupa os
// vertices em componentes 2-aresta-conexas (particao definida pelas bridges)
//
// Complexidades:
// dfs - O(n + m)
//
// grafo global graph[MAX]; chamar dfs(v, -1) para cada componente conexa nao visitada
// comp[v] = id da componente 2-aresta-conexa de v (1-indexado, comeca em 1)
// compgraph[c] = lista de vertices originais dentro da componente c
// NAO monta as arestas da bridge tree entre componentes, so agrupa os vertices;
// para isso, conectar comp[u]-comp[v] para cada aresta original (u,v) com comp[u] != comp[v]
// assume grafo simples (sem arestas paralelas entre o mesmo par de vertices)

int t, c, low[MAX], pre[MAX], visited[MAX], comp[MAX];
stack<int> st;
vector<int> graph[MAX], compgraph[MAX];

void dfs(int v, int p){
    visited[v] = 1;
    low[v] = pre[v] = ++t;
    st.emplace(v);
    for (auto u : graph[v]){
        if (!visited[u]){
            dfs(u,v);
            low[v] = min(low[v], low[u]);
        }   
        else {
            if (u == p) continue;
            low[v] = min(low[v], pre[u]);
        }
    }
    if (low[v] == pre[v]){ //achamos uma bridge
        c++;
        int cur;
        do {
            cur = st.top();
            st.pop();
            comp[cur] = c;
            compgraph[c].push_back(cur);
        } while(cur != v);
    }
}