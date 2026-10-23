#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n, k;
    cin >> n >> k;
    if ((n/k)%(k+1) == n%k) cout << "Thiago" << endl;
    else cout << "Trojack" << endl;
}