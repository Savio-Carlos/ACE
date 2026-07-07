#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

const int MOD = 1e9+7;
const int MAXN = 1e6+7;
int fat[MAXN], inv[MAXN];


int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    int par = n/2, impar = n/2;
    if(n&1) impar++;
    int inv6 = fastexpo(6, MOD-2);
    int inv2 = fastexpo(2, MOD-2);

    int ans = (par*(par-1))%MOD;
    ans = (ans*(par-2))%MOD;
    ans = (ans * inv6)%MOD;

    int ans2 = (impar*(impar-1))%MOD;
    ans2= (ans2*inv2)%MOD;
    ans2=(ans2 * par)%MOD;

    cout << ((ans + ans2)%MOD) << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}