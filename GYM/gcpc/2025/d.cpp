#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    int xmn = 1e10;
    int xmx = 0;
    int ymn = 1e10;
    int ymx = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        xmx = max(xmx, x);
        xmn = min(xmn, x);
        ymx = max(ymx, y);
        ymn = min(ymn, y);
    }
    cout << 4 << endl;
    cout << xmx << " " << ymx << endl;
    cout << xmn << " " << ymx << endl;
    cout << xmn << " " << ymn << endl;
    cout << xmx << " " << ymn << endl;
}

