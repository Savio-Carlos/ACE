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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    string s;
    cin >> s;

    vector<int> b(n, 1);
    for (int i = 0; i < n - 1; i++){
        if (s[i] == '<') b[i+1] = max(b[i+1], b[i] + 1);
        else if (s[i] == '=') b[i+1] = max(b[i+1], b[i]);
    }
    for (int i = n - 2; i >= 0; i--){
        if (s[i] == '>') b[i] = max(b[i+1] + 1, b[i]);
        else if (s[i] == '=') b[i] = max(b[i+1], b[i]);
    }
    int ans = 0;

    for (int i = 0; i < n; i++){
        ans = ans + b[i] * a[i];
    }
    cout << ans << endl;
    for (auto u : b) cout << u << " ";
    cout << endl;
}