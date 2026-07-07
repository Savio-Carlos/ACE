#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MOD = 1e9+7;

int fastExpo(int b, int e){
    int res = 1;
    while (e){
        if (e&1) res = res * b % MOD;
        b = b*b % MOD;
        e >>= 1;
    }
    return res%MOD;
}

int modiv(int a, int b){
    return (a * fastExpo(b, MOD-2) % MOD) % MOD;
}

const int d = 365;

void solve(){
    int n, x;
    cin >> n >> x;

    int k = n - x;

    if (k >= d){
        cout << 0 << endl;
        return;
    }
    int num = 1;
    for (int i = n; i > n-k; i--){
        num = num*(i%MOD) % MOD;
    }
    int den = 1;
    for (int i = 1; i <= k; i++){
        den = (den*i) % MOD;
    }

    int comb = modiv(num, den);
    // cout << "comb: "<< comb << endl;
    int ans = (d * comb) % MOD;
    for (int i = 1; i <= k; i++){
        ans = (ans * ((d - i + MOD) % MOD)) % MOD;
    }
    int res = modiv(ans, fastExpo(d, n) % MOD);
    cout << res%MOD << endl;

}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--) solve();   

}