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
    int m,n ;
    cin >> m >> n;

    ld ea = 0;
    for (int i = 0; i < m; i++){
        ld x;
        cin >> x;
        ea += (x*(x+1)/2.0) / x;
    }

    ld ej = 0;
    for (int i = 0; i < n; i++){
        ld x;
        cin >> x;
        ej += (x*(x+1)/2.0) / x;
    }
    // cout << ea << " " << ej << endl;
    if (ea > ej) cout << "JuliAna" << endl;
    else if (ea < ej) cout << "KauAna" << endl;
    else cout << "empate" << endl;
}