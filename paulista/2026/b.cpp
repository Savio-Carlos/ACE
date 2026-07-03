#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, c, k;
    cin >> n >> c >> k;
    int ans = 0;
    int last = -1e9;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans += min((x-last)*c, k+c);

        last = x;
    }   
    cout << ans << endl;
}