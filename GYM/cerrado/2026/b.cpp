#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define ld long double

signed main(){
    fastio;
    int n; cin >> n;
    if(n == 45) cout <<"Ambos\n";
    else if(n < 45) cout << "Costa\n";
    else cout <<"Saad" << endl;
}