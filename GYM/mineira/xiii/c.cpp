#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 2e5+7;

int arr[MAX];

namespace SegTree{
    pair<int,int> tree[4*MAX];
    int n, *v;

    pair<int,int> build(int node = 1, int l = 0, int r = n-1){
        if (l == r) return tree[node] = {-1,-1};
        int m = (l+r)/2;
        return max(build(2*node, l, m),build(2*node+1, m+1, r));
    }

    void build(int n2, int* v2){
        n = n2;
        v = v2;
        build();
    }

    pair<int,int> query(int a, int b, int node = 1, int l = 0, int r = n-1){
        if (b < l or r < a) return {-1,-1};
        if (a <= l and r <= b) return tree[node];
        int m = (l+r)/2;
        return max(query(a, b, 2*node, l, m),query(a, b, 2*node+1, m+1, r));
    }

    void update(int i, pair<int,int> x, int node = 1, int l = 0, int r = n-1){
        if (l == r){
            tree[node] = x;
            return;
        }
        int m = (l+r)/2;
        if (i <= m) update(i,x, 2*node, l, m);
        else update(i, x, 2*node+1, m+1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}


signed main(){
    fastio;
    int n;
    cin >> n;
    SegTree::build(n+1, arr);

    vector<int> last(n+1, -1);
    int cur = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (last[x] != -1) cur = max(cur, last[x] + 1);
        last[x] = i;
        SegTree::update(i, {x,i});

        auto [numero, quem] = SegTree::query(cur, i);
        cout << numero << " " << quem+1 << endl;
    }
}