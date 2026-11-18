#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define debug(x) cerr << #x << ": " << x << endl;

const ld eps = 1e-9;

void solve(){
    int x1,y1,r1;
    int x2,y2,r2;
    int k;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> k;

    if (k <= 2*r1 or k <= 2*r2) {
        cout << "YES" << endl;
        return;
    }

    int dist = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    
    if ((r1+r2 * r1+r2) < dist) {
        cout << "NO" << endl;
        return;
    }
    
    ld meio = (sqrt(dist));
    if ((ld)(r1 + r2) + meio + eps >= (ld)k) cout << "YES" << endl;
    else cout << "NO" << endl;

    
}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--) solve();   

}