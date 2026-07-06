#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 2e6+7;

int a[MAX];

namespace SegTreeBits {
    int tree[4*MAX];
    int cnt[4*MAX];
    int lazy_set[4*MAX];
    int n, *v;

    int build(int node = 1, int l = 0, int r = n-1) {
        lazy_set[node] = -1;
        if (l == r) {
            cnt[node] = v[l+1] - v[l];
            return cnt[node];
        }
        int m = (l + r)/2;
        return cnt[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
    }

    void build(int n2, int* v2) {
        n = n2; v = v2;
        build();
    }

    inline void apply_set(int node, int l, int r, int x) {
        tree[node] = x * cnt[node];
        lazy_set[node] = x;
    }

    void prop(int node, int l, int r) {
        if (l == r) return;
        int m = (l + r)/2;
        if (lazy_set[node] != -1) {
            apply_set(2*node, l, m, lazy_set[node]);
            apply_set(2*node+1, m+1, r, lazy_set[node]);
            lazy_set[node] = -1;
        }
    }

    int query(int a, int b, int node = 1, int l = 0, int r = n-1) {
        if (b < l || r < a) return 0;
        if (a <= l && r <= b) return tree[node];
        prop(node, l, r);
        int m = (l + r)/2;
        return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
    }

    int range_set(int a, int b, int x, int node = 1, int l = 0, int r = n-1) {
        if (b < l || r < a) return tree[node];
        if (a <= l && r <= b) {
            apply_set(node, l, r, x);
            return tree[node];
        }
        prop(node, l, r);
        int m = (l + r)/2;
        return tree[node] = range_set(a, b, x, 2*node, l, m) + range_set(a, b, x, 2*node+1, m+1, r);
    }
}

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> todos;
    vector<tuple<int,int,int>> queries(q);
    for (auto &[l,r,k] : queries){
        cin >> l >> r >> k;
        l--;r--;k--;
        todos.push_back(l);
        todos.push_back(l+1);
        todos.push_back(r);
        todos.push_back(r+1);
    } 
    todos.push_back(0);
    todos.push_back(n);
    
    sort(all(todos));
    todos.erase(unique(all(todos)), todos.end());
    auto comp = [&](int x) -> int{
        return (lower_bound(all(todos),x) - todos.begin());
    };
    
    int N = todos.size() - 1;
    for (int i = 0; i < todos.size(); i++){
        a[i] = todos[i];
    }

    SegTreeBits::build(N,a);
    SegTreeBits::range_set(0,N-1,1);
 
    for (auto [l,r,k] : queries){
        l = comp(l);
        r = comp(r);
        SegTreeBits::range_set(l,r,k);
        cout << SegTreeBits::query(0, N-1) << endl;
    } 
}
