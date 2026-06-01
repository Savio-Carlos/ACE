#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)


signed main(){
    fastio;
    int d, m;
    cin >> d >> m;
    if (d == m) cout << "DATA SEGURA" << endl;
    else if (d <= 12 && m <= 12) cout << "DATA INCERTA" << endl;
    else cout << "DATA SEGURA" << endl;
}