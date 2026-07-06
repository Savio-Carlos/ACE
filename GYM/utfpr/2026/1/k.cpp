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
    int n,q; cin >> n >> q;
    vector<pair<int, int>> v;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        v.push_back({x, i});
    }

    v.push_back({n+1, q});
    sort(v.begin(), v.end());

    vector<int> ans(q, 0);
    int best = 0;
    for(int i = q-1; i >= 0; i--){
        int diff = v[i+1].first - v[i].first-1;
        //cout << v[i+1].first << "  " << v[i].first << " " << diff << endl;
        best = max(best, diff);
        ans[v[i].second] = best;
    }

    for(auto u : ans) cout << u << " ";
    cout << endl;

}