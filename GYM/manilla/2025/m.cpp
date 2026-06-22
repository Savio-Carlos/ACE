#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)


void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>>grid(n,vector<int>(m));
    for (auto &u : grid){
        for(auto &i : u) cin >> i;
    }

    vector<int> d(m);
    for(auto &u : d) cin >> u;

    auto f1 = [&]() -> int {
        int tot = (1 << m) - 1;

        ll ans = 1e18;

        for (int mask = 1; mask <= tot; mask++){
            ll cur = 0;
            for (int pos = 0; pos < m; pos++){
                if ((1 << pos) & mask){
                    cur += d[pos];
                }
            }

            for (int li = 0; li < n; li++){
                ll mn = 1e16;
                for (int co = 0; co < m; co++){
                    if ((1 << co) & mask){
                        mn = min(mn, grid[li][co]);
                    }
                }
                cur += mn;
            }
            ans = min(ans, cur);
        }

        return ans;

    };



    if (m <= n) cout << f1() << endl;
    else cout << f2() << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--)solve();
}