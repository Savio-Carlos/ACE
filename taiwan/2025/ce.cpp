#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    vector<int> score(n, 0);
    vector<tuple<int, int, int>> vec; 
    for(int i = 0; i < m; i++){
        int a, b, v; cin >> a >> b >> v;
        a--, b--;
        vec.push_back({a, b, v});
    }


    for(int i = m-1; i >= 0; i--){
        auto [l, r, v] = vec[i];
        int sl = score[l];
        int sr = score[r];
        score[r] = v + sl;
        score[l] = v + sr;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, score[i]);
    cout << ans << endl;

}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
