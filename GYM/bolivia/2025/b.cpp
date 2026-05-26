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
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        int ans = 0, aux;
        for(int i = 0; i < k; i++){
            cin >> aux;
            ans += 1LL << (aux - 1);
        }
        cout << ans << endl;
    }
}