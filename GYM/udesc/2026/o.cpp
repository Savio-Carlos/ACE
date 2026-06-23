#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MAX = 2e5+7;

int z[MAX];

namespace Segtree {
    int tree[4*MAX], lazy[4*MAX];
    int n, *v;
    
    void build(int node = 1, int l = 0, int r = n-1){
        lazy[node] = 0;
        tree[node] = 0;
        if (l == r) return;
        int m = (l+r)/2;
        build(node*2, l, m);
        build(node*2+1, m+1, r);
    }

    void build(int n_, int *v_){
        n = n_;
        v = v_;
        build();
    }

    void prop(int node, int l, int r){
        if (lazy[node] != 0){
            tree[node] += lazy[node];
            if (l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
        }
        lazy[node] = 0;
    }

    int query(int a, int b, int node = 1, int l = 0, int r = n-1){
        prop(node, l, r);
        if (a > r or b < l) return 0;
        if (a <= l and b >= r) return tree[node];
        int m = (l+r)/2;
        return max(query(a, b, node*2, l, m), query(a, b, node*2+1, m+1, r));
    }

    void update(int a, int b, int x, int node = 1, int l = 0, int r = n-1){
        prop(node, l, r);
        if (a > r or b < l) return;
        if (l >= a and r <= b) {
            lazy[node] += x;
            prop(node, l, r);
            return;
        }
        int m = (l+r)/2;
        update(a, b, x, node*2, l, m); 
        update(a, b, x, node*2+1, m+1, r);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

}

signed main(){
    winton;
    int n, l;
    cin >> n >> l;
    int mx = 0;
    vector<vector<int>> pts(MAX);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >>x>>y;
        mx = max(x, mx);
        pts[x].push_back(y);
    }
    
    int ans = 0;
    
    Segtree::build(MAX, z);
    
    for (int hi = 0; hi <= mx; hi++){
        int lo = hi - l - 1;
        if (lo >= 0 && !pts[lo].empty()){
            for(auto u : pts[lo]) Segtree::update(max(0LL, u-l), u, -1);
        }
        
        for(auto u : pts[hi]){
            Segtree::update(max(0LL, u-l), u, 1);
        } 

        ans = max(ans, Segtree::query(0LL, MAX-1));
    }
    cout << ans << endl;
}

