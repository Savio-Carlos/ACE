#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
 
signed main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    sort(rall(a));
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (l >= (100-a[i])){
            l -= (100 - a[i]);
            ans++;
        }
        else break;
    }
    cout << ans << endl;
}