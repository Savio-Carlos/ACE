#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define debug(x) cerr << #x << ": " << x << endl;


const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

int modmult(int a, int b){
    return (a*b)%MOD;
}

const int MAX = 1e6+7;

int porra[MAX];
int porra2[MAX];

int modiv(int a, int b){
    return (a * fastexpo(b, MOD-2)) % MOD;
}

signed main(){
    fastio;
    int t; cin >> t;
    int cur = 0;
    for (int i = 3; i < MAX; i++){
        porra[i] = porra[i-1];
        if (i&1)porra[i]++;
        cur = (cur + porra[i]) % MOD;
        porra2[i] = cur;
        if (i < 11){
            // debug(porra[i]);
            // debug(porra2[i]);
        }
    }

    int prev = -1;
    while(t--){
        int n; cin >> n;
        // int modinv = fastexpo(2, MOD-2);
        int modinv6 = fastexpo(6, MOD-2);
        // int val = 0;
        // if(!(n&1)) val = (((n*modinv)%MOD)-1+MOD)%MOD;
        // else val = (n*modinv)%MOD;  
        // cout << val << endl;
        // int arit = ((val*2)%MOD);
        // arit = (2 + arit)%MOD;
        // cout << arit << endl;
        // arit = (arit*val)%MOD;
        // cout << arit << endl;
        // arit = (arit*modinv)%MOD;

        // int res = ((val*n) - arit + MOD)%MOD;

        // int ppa = (n-1)/2;
        // debug(ppa);
        // int pa = (ppa * (ppa+1))/2;
        // debug(pa);
        // int res = pa + (n&1 ? 0 : ppa);

        int res = porra2[n];
        int newn = n-2;

        int y = (newn*(newn+1))%MOD;
        int tot = ((4 + 2*newn) * y) % MOD;
        int inv12 = fastexpo(12, MOD-2);
        tot = (tot * inv12) % MOD;
        
        // debug(tot);
        // debug(res);
        // debug(modinv6);

        // debug(modiv(20,120));

        int cur = modiv(res,tot)%MOD;
        if (prev != -1) cur = (cur * prev) % MOD;
        cout << cur << endl;
        prev = cur;
    }
}