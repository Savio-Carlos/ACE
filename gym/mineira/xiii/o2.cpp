#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MOD = 1e9+7;

signed main(){
    fastio;
    int n; cin >> n;

    int var = 1, soma = 0;

    while(n--){
        int x;
        char op; cin >> op >> x;

        if(op == '+'){
            soma += x;
            soma %= MOD;
        }

        if(op == '*'){
            soma = (soma * x) % MOD;
            var = (var * x) % MOD;
        }

        if(op == '?'){
            cout << ((x * var) % MOD + soma) % MOD << endl;
        }
    }


}