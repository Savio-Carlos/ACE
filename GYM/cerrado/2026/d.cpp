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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> primeiro(26, 0);
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < n; j++){
            if (s[j] == i + 'a'){
                primeiro[i] = j;
                break;
            }
            primeiro[i] = n;
        }
        // cout << i << ": " << primeiro[i] << endl;
    }

    while(q--){
        string t;
        cin >> t;
        int m = t.size();
        int ans = 0;
        int i = 0;
        while (t[i] == s[0]) i++;

        int pos1 = n + m-i;
        int best = n;
        for (int j = 0; j < 26; j++){
            if (j != t[0]-'a') best = min(best,primeiro[j]);
        }
        int pos2 = m + n-best;

        // cout << pos1 << " - " << pos2 << endl;

        ans = max(pos1, pos2);
        ans = max(ans, n);
        ans = max(ans, m);
        cout << ans << endl;
    }
}