#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

signed main(){
    fastio;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int ans = 0;
    for (int i = 0; i+m <= n; i++){
        bool pos = true;
        for (int j = 0; j < m; j++){
            if (s[i+j] == t[j]){
                pos = false;
                break;
            } 
        }
        if (pos) ans++;
    }
    cout << ans << endl;
}