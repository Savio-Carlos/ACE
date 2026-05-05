#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAXN = 400005; // N + Ciclos (M pode ser até 300k, máximo de 200k ciclos)
const int LOG = 20;

struct Edge {
    int to;
    long long weight;
};

int n, m, q;
vector<Edge> adj[MAXN];
vector<Edge> bct[MAXN];

// Estruturas da DFS para achar ciclos
int dfn[MAXN], low[MAXN], timer = 0;
int par[MAXN];
long long weightToPar[MAXN];
int depth_dfs[MAXN]; // Crucial para resolver o problema de pesos negativos
int num_nodes;

long long S_C[MAXN]; // Peso total de cada ciclo
long long pos[MAXN]; // Posição do vértice no ciclo (Prefix Sum direcional)

void build_dfs(int u, int p) {
    dfn[u] = low[u] = ++timer;
    depth_dfs[u] = depth_dfs[p] + 1;

    for (auto& edge : adj[u]) {
        int v = edge.to;
        if (v == p) continue;

        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
            // Encontramos uma Back-Edge! Isso forma um ciclo.
            if (dfn[v] < dfn[u]) { 
                int C = ++num_nodes; // Novo Nó Quadrado (Ciclo)
                S_C[C] = edge.weight;
                int curr = u;
                
                // Primeiro pass: calcula o perímetro total do ciclo
                while (curr != v) {
                    S_C[C] += weightToPar[curr];
                    curr = par[curr];
                }

                // O topo do ciclo (v) liga no quadrado com peso 0
                bct[v].push_back({C, 0});
                bct[C].push_back({v, 0});

                curr = u;
                long long current_pos = edge.weight; // Começa da back-edge
                
                // Segundo pass: calcula as posições relativas e arestas da BCT
                while (curr != v) {
                    pos[curr] = current_pos;
                    long long shortest_to_v = min(current_pos, S_C[C] - current_pos);
                    
                    bct[C].push_back({curr, shortest_to_v});
                    bct[curr].push_back({C, shortest_to_v});

                    current_pos += weightToPar[curr];
                    curr = par[curr];
                }
            }
        } else {
            par[v] = u;
            weightToPar[v] = edge.weight;
            build_dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > dfn[u]) { 
                // É uma ponte! Conecta os nós redondos diretamente
                bct[u].push_back({v, edge.weight});
                bct[v].push_back({u, edge.weight});
            }
        }
    }
}

// Estruturas do Binary Lifting para a BCT
int up[MAXN][LOG];
int depth[MAXN];
long long dist[MAXN];

void dfs_bct(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto& edge : bct[u]) {
        int v = edge.to;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + edge.weight; // Distância acumulada na árvore
        dfs_bct(v, u);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

long long query(int u, int v) {
    if (u == v) return 0;
    int l = get_lca(u, v);

    if (l <= n) {
        // LCA é Nó Redondo: Matemática tradicional de Árvores
        return dist[u] + dist[v] - 2 * dist[l];
    } else {
        // LCA é Nó Quadrado (Ciclo): Subimos até os filhos diretos do ciclo (X e Y)
        int X = u;
        int diffX = depth[X] - depth[l] - 1;
        for (int i = 0; i < LOG; i++) {
            if ((diffX >> i) & 1) X = up[X][i];
        }

        int Y = v;
        int diffY = depth[Y] - depth[l] - 1;
        for (int i = 0; i < LOG; i++) {
            if ((diffY >> i) & 1) Y = up[Y][i];
        }

        // Calcula distância dentro do ciclo lidando perfeitamente com pesos negativos!
        long long W;
        if (depth_dfs[X] > depth_dfs[Y]) {
            W = pos[Y] - pos[X];
        } else {
            W = pos[X] - pos[Y];
        }

        long long dist_cycle = min(W, S_C[l] - W);
        
        // Retorna o atalho sem passar pelo topo do ciclo
        return (dist[u] - dist[X]) + (dist[v] - dist[Y]) + dist_cycle;
    }
}

signed main() {
    winton;
    cin >> n >> m >> q;
    num_nodes = n; // Nós > n serão nossos Nós Quadrados

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    depth_dfs[0] = 0;
    build_dfs(1, 0); // Pré-processamento do Cactus -> BCT

    depth[1] = 0;
    dist[1] = 0;
    dfs_bct(1, 1); // Pré-processamento do LCA / Distâncias na BCT

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << "\n";
    }

    return 0;
}