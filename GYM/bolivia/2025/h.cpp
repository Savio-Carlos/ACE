#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    string s;
    cin >> s;
    int cur = 0, best = 0, ans = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '+') cur++;
        else cur--;
        if (cur > best){
            best = cur;
            ans = i+1;
        }
    }
    cout << ans << endl;

}