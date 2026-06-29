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
    int d, c, r;
    cin >> d >> c >> r;
    vector<int> ci(c);
    for (auto &u : ci) cin >> u;
    vector<int> ri(r);
    for (auto &u : ri) cin >> u;
    int cur = d;
    int ans = 0;
    for(int i = 0, j = 0; i < c; i++){
        while(j < r && cur < ci[i]){
            cur += ri[j];
            j++;
        }
        if (cur >= ci[i]){
            ans++;
            cur -= ci[i];
        }
        else break;
    }
    cout << ans+r << endl;
}