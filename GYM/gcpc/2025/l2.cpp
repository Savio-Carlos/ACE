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
    int n; cin >> n;
    if(n <= 360) cout << 0 << endl;
    else if(n > 360 && n <= 570) cout <<  min<int>(30, n - 360) << endl;
    else if(n > 570 && n <= 645) cout << min<int>(45, n - 540) << endl;
    else cout << n-600 << endl;
}