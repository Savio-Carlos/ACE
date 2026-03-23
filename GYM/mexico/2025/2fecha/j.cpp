#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int MOD = 998244353;
const int MAXN = 1e6+7;
int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

signed main(){
    fastio;
    int q; cin >> q;
    vector<int> fat(MAXN, 0), inv(MAXN, 0);
    fat[0] = 1;
    fat[1] = 1;
    inv[0] = fastexpo(fat[0], MOD-2);
    inv[1] = fastexpo(fat[1], MOD-2);
    for(int i = 2; i < MAXN; i++){
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = fastexpo(fat[i], MOD-2);
    }
    while(q--){
        int n, k; cin >> n >> k;
        n++, k++;
        cout << ((fat[n] * inv[k])%MOD * inv[n-k])%MOD << endl;
    }
}