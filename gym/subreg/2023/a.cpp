#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, h, ans = 0;
    cin >> n >> h;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= h) ans++;
    }
    cout << ans << endl;
}