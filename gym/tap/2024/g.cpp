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
    string s;
    cin >> s;
    int au = 0, p = 0, t = 0;
    for (auto &c : s){
        if (c == 'U' || c == 'A') au++;
        if (c == 'T') t++;
        if (c == 'P') p++;
    }
    cout << min({au, p, t}) << endl;
}