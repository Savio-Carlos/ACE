#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v, v2;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        int aux;

        cin >> aux;
        x += aux;
    }
    x *= 100;
    for(int i = 0; i < m; i++){
        int aux;
        cin >> aux;
        y += aux;
    }

    y *= 100;

    if (y >= x + x / 10) cout << "YES" << endl;
    else cout << "NO" << endl;



}