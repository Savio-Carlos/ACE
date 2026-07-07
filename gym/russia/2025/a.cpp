#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    fastio;
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans += x/k;
        ans += (x%k > 0);
    }   
    cout << ans << endl;
}