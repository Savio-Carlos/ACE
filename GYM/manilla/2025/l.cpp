#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MOD = 1006903069;

signed main(){
    fastio;
    int t; cin >> t;
    int n; cin >> n;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++){
        int x, y, v; cin >> x >> y >> v;
        mp[{x, y}] += v;
        mp[{x, y}]%=MOD;
    }

    int m; cin >> m;
    int ans =0;
    for(int i = 0; i < m; i++){
        int x, y, v; cin >> x >> y >> v;
        //cout << x << " " << y << " " << y << " " << x << " " << mp[{y, x}] << endl;
        int c = mp[{y, x}];
        ans = (ans + (c*v)%MOD)%MOD;
    }
    cout << ans << endl;
}