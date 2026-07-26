#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;


const int MAX = 1e5+7;

namespace SegTree {
	int tree[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int node=1, int l=0, int r=n-1) {
		lazy[node] = 0;
		if (l == r) return tree[node] = v[l];
		int m = (l+r)/2;
		return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int node, int l, int r) {
		tree[node] += lazy[node]*(r-l+1);
		if (l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
		lazy[node] = 0;
	}
	int query(int a, int b, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) return tree[node];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
	}
	int update(int a, int b, int x, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) {
			lazy[node] += x;
			prop(node, l, r);
			return tree[node];
		}
		if (b < l or r < a) return tree[node];
		int m = (l+r)/2;
		return tree[node] = update(a, b, x, 2*node, l, m) + update(a, b, x, 2*node+1, m+1, r);
	}
}

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		SegTree::build(t, v);
	}
	int query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return SegTree::query(pos[b], pos[a]);
		return SegTree::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)SegTree::update(pos[b], pos[a], x);
		SegTree::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
}

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        v--; u--;
        hld::g[v].push_back(u);
        hld::g[u].push_back(v);
    }
    hld::build();

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        hld::update_path(a,b,1);
        cout << hld::query_path(c,d) << endl;
        hld::update_path(a,b,-1);
    }
}