// Minimum Spanning Tree (Kruskal)
//
// Acha o custo da MST de um grafo ponderado nao dirigido, ordenando as
// arestas por peso e unindo componentes com DSU (union by size)
//
// Complexidades:
// solve - O(m log(m))
//
// solve() le o grafo e acumula o custo em cost; se precisar reconstruir a
// arvore, guardar as arestas (u, v) toda vez que dsu.merge(u, v) retornar true

struct DSU {
	vector<int> comp, sz;

	DSU(int n) : comp(n), sz(n, 1) {
		iota(all(comp), 0);
	}

	int find(int u) {
		if (u == comp[u]) return u;
		return comp[u] = find(comp[u]);
	}

	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		sz[a] += sz[b];
		comp[b] = a;
		return true;
	}
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges; 
    DSU dsu(n);
    edges.resize(m);
       for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w,a,b};
    }
    sort(all(edges));
    int cost = 0;
    for(int i = 0; i < m; i++){
        auto [w,u,v] = edges[i];
        if (dsu.merge(u,v)){
            cost += w;
        }
    }
}