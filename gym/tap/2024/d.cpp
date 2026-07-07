#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int x, y, z;
    cin >> x >> y >> z;
    bool p = false;
    if(x + y <= z) p = true;
    if(x + z <= y) p = true;
    if(y + z <= x) p = true;
    if(p) cout << "S" << endl;
    else cout << "N" << endl;
}