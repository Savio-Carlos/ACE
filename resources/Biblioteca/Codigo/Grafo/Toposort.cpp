// Toposort (Kahn / BFS)
//
// Ordena topologicamente um DAG processando os vertices de indegree 0 em uma fila
//
// Complexidades:
// O(n + m)
//
// requer indeg[MAX] e graph[MAX] (lista de adjacencia) ja preenchidos;
// fazer uma dfs/varredura das arestas antes pra calcular o indeg se necessario
// o loop inicial percorre ate MAX (nao ate n): se MAX > n, vertices "fantasma"
// (indeg 0 por serem indices nao usados) tambem entram em order -- ajustar o limite
// trecho solto (fora de funcao), copiar direto no main onde for usar
int indeg[MAX];

vector<int> order;
queue<int> q;

for (int i = 0; i < MAX; i++){
    if (indeg[i] == 0)q.push(i);
}
while(!q.empty()){
    int cur = q.front();   
    order.push_back(cur);
    q.pop();
    for (auto u : graph[cur]){
        indeg[u]--;
        if (indeg[u] == 0)q.push(u);
    }
}
