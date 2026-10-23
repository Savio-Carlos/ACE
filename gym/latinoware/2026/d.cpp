#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int mid = n/2, ans = 0, amnt = 0;
    // if(!(n&1)) mid++;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(b >= k){
            ans += a; 
            k++;
            amnt++;
        }
    }

    if(amnt > mid){
        ans = -1;            
    }
    cout << ans << endl;
}