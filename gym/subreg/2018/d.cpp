#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x != 1) ans++;
    }
    cout << ans << endl;

}