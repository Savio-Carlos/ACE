#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (auto &[u, v]: a) cin >> u >> v;
    sort(all(a), [](auto x, auto y){
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    // for (auto &[u, v]: a) cout << u << v << endl;;
    int ans = 0, r = -1, l = -1;
    for (int i = 0; i < n; i++){
        auto [st, en] = a[i];
        if (st >= r){
            r = en;
            l = st;
            ans++;
        }
    }
    cout << ans << endl;
}