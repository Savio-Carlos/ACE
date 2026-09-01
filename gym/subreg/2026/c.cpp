#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    fastio;
    int t, c, k;
    cin >> t >> c >> k;
    cout << min(t *k, c) << endl;
}