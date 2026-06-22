#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, b;
    cin >> n >> b;
    bool pos = false;
    bool can = false;

    int ans = 0;
    int mn = -1e12;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        if (x > 0LL){
            pos = true;
            ans += x;
        }
        else if (llabs(x) <= b){
            can = true;
            mn = max(mn, x);
        }
    }
    if (pos) cout << ans+b << endl;
    else if (can) cout << b + mn << endl;
    else cout << -1 << endl;
    
}