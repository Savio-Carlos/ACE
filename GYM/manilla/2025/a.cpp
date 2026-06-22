#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;string s;
    cin >> s;

    if(s.size() % 2 == 0) cout << ":)" << endl;
    else cout << s[s.size() / 2] << endl;    
}