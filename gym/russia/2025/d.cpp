#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

struct SegTree {
    int n;
    vector<pair<int,int>> tree; // {dp, idx}

    void init(int _n) {
        n = _n;
        tree.assign(4*n, {0, -1});
    }

    void update(int pos, pair<int,int> val, int node, int l, int r) {
        if (l == r) {
            if (val.first > tree[node].first) tree[node] = val;
            return;
        }
        int m = (l+r)/2;
        if (pos <= m) update(pos, val, 2*node, l, m);
        else update(pos, val, 2*node+1, m+1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    pair<int,int> query(int a, int b, int node, int l, int r) {
        if (a > r || b < l) return {0, -1};
        if (a <= l && r <= b) return tree[node];
        int m = (l+r)/2;
        return max(query(a, b, 2*node, l, m), query(a, b, 2*node+1, m+1, r));
    }

    void update(int pos, pair<int,int> val) { update(pos, val, 1, 0, n-1); }
    pair<int,int> query(int a, int b) {
        if (a > b) return {0, -1};
        return query(a, b, 1, 0, n-1);
    }
};

signed main(){
    fastio;

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    auto todos = a;
    sort(all(todos));
    todos.erase(unique(all(todos)), todos.end());
    int m = todos.size();

    auto comp = [&](int x) {
        return (lower_bound(all(todos), x) - todos.begin());
    };

    // up[i]   = maior subseq oscilante comecando em i com a[i] < proximo (subida)
    // down[i] = maior subseq oscilante comecando em i com a[i] > proximo (descida)
    vector<int> up(n, 1), down(n, 1);
    vector<int> nxt_up(n, -1), nxt_down(n, -1);

    SegTree segUp, segDown;
    segUp.init(m);
    segDown.init(m);

    for (int i = n-1; i >= 0; i--) {
        int c = comp(a[i]);
        // para subir de a[i], preciso de a[j] > a[i] com maior down[j]
        auto [vd, idxd] = segDown.query(c+1, m-1);
        if (idxd != -1) {
            up[i] = vd + 1;
            nxt_up[i] = idxd;
        }
        // para descer de a[i], preciso de a[j] < a[i] com maior up[j]
        auto [vu, idxu] = segUp.query(0, c-1);
        if (idxu != -1) {
            down[i] = vu + 1;
            nxt_down[i] = idxu;
        }

        segUp.update(c, {up[i], i});
        segDown.update(c, {down[i], i});
    }

    int best = 0, bestIdx = -1, bestState = 0; // 0 = up, 1 = down
    for (int i = 0; i < n; i++) {
        if (up[i] > best) { 
            best = up[i];   
            bestIdx = i; 
            bestState = 0; 
        }
        if (down[i] > best) { 
            best = down[i]; 
            bestIdx = i; 
            bestState = 1; 
        }
    }

    if (best < 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;
    int cur = bestIdx, st = bestState;
    while (cur != -1) {
        ans.push_back(cur);
        int nx = (st == 0) ? nxt_up[cur] : nxt_down[cur];
        st ^= 1;
        cur = nx;
    }

    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
} 
