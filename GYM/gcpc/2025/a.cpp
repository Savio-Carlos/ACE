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
    int l, r;
    cin >> l >> r;
    int tot = l + r;
    if (l == r || l-2 == r) cout << tot + tot/2 << endl;
    else if (l == r+1) cout << tot << endl;
    else cout << 2*tot << endl;
}