#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL)

const int MAX = 2e5+7;
const int INF = INT_MAX;

int arr[MAX];

namespace SegTree{
    int tree[4*MAX];
    int n;
    int *v;

    int build(int node = 1, int l = 0, int r = n-1){
        if (l == r) return tree[node] = v[l];
        int m = (l + r) / 2;
        build(2*node, l, m);
        build(2*node + 1, m+1, r);
        return tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    void init(int n2, int *v2){
        n = n2;
        v = v2;
        build();
    }

    int query(int a, int b, int node = 1, int l = 0, int r = n-1){
        if (a <= l and r <= b) return tree[node];
        if (b < l or r < a) return 0;
        int m = (l+r)/2;
        return max(query(a,b,2*node,l,m), query(a,b,2*node+1,m+1,r));
    }
};

namespace hld {
    vector<pair<int,int>> g[MAX];
    int pos[MAX], sz[MAX];
    int sobe[MAX], pai[MAX];
    int h[MAX], v[MAX], t;

    void build_hld(int k, int p = -1, int f = 1){
        v[pos[k] = t++] = sobe[k];
        sz[k] = 1;
        for (auto &i : g[k]) if(i.first != p){
            auto [u,w] = i;
            sobe[u] = w;
            pai[u] = k;
            h[u] = (i == g[k][0] ? h[k] : u);
            build_hld(u,k,f);
            sz[k] += sz[u];
            
            if (sz[u] > sz[g[k][0].first] or g[k][0].first == p) swap(i, g[k][0]);
        }
        if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
    }
    void build(int root = 0){
        t = 0;
        build_hld(root);
        SegTree::init(t,v);
    }
    int query_path(int a, int b){
        if (a == b) return 0;
        if (pos[a] < pos[b]) swap(a,b);

        if (h[a] == h[b]) return SegTree::query(pos[b]+1, pos[a]);
        return max(SegTree::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
    }
}

struct DSU {
    vector<int> comp, sz;

    DSU(int n):comp(n),sz(n,1){
        iota(all(comp), 0);
    }

    int find(int u){
        if (u == comp[u]) return u;
        return comp[u] = find(comp[u]);
    }

    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        comp[b] = a;
        return true;
    }
};

signed main(){
    fastio;
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int,int,int>> edges(m);
    for(auto &[w,u,v] : edges) cin >> u >> v >> w;
    sort(all(edges));

    DSU dsu(n+1);

    for(int i = 0; i < m; i++){
        auto [w,u,v] = edges[i];
        u--;
        v--;
        if (dsu.merge(u,v)){
            hld::g[u].push_back({v,w});
            hld::g[v].push_back({u,w});
        }
    }

    int origem = dsu.find(0);
    for (int i = 1; i < n; i++){
        int bb = dsu.find(i);
        if (dsu.merge(i, origem)){
            hld::g[origem].push_back({bb,INF});
            hld::g[bb].push_back({origem,INF});
        }
    }

    hld::build();

    while(q--){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        int ans = hld::query_path(s,t);
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}