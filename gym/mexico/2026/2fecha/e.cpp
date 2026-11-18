#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    string s;
    cin >> s;
    int n = s.size();
    string t = "taquero";   
    string ans = "";
    for (int i = 0; i < n; i++){
        if (i < n-5 and s.substr(i,6) == "mesero"){
            ans += t;
            i += 5;
        }
        else ans += s[i];
    }

    cout << ans << endl;
}