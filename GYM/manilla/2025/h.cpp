#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 10000010;

vector<int> primes;
vector<bool> is_prime(MAX + 1, true);

void sieve(){
    is_prime[0] = false;
    is_prime[1] = false;
    for(int p = 2; p * p <= MAX; ++p){
        if(is_prime[p]){
            for(int multiple = p* p; multiple <= MAX; multiple += p){
                is_prime[multiple] = false;
            }
        }
    }
    for(int i = 2; i <= MAX; ++i){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

vector<int> brimos(int n){
    vector<int> res;
    for(int i = 0; i < primes.size(); i++){
        if(primes[i] > n) break;
        res.push_back(primes[i]);
    }
    return res;
}

const int MOD = 104206969;

signed main(){
    fastio;

    sieve();

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        auto primos = brimos(n);

        if(k == 1){
            cout << n + 1 << endl;
        } else if(k == 2){
            int ans = 0;
            for(int i = 0; i < primos.size(); i++){
                ans += n - primos[i];
                ans %= MOD;
            }
            cout << ans << endl;

        } else if (k == 3){
            int ans = 0;
            vector<int> aux;
            for(int i = 0; i < primos.size(); i++){
                if(is_prime[primos[i] + 2]){
                    if(n - primos[i] - 2 > 0) ans += n - primos[i] - 2 + MOD;
                    ans %= MOD;
                }
            }
            cout << (2 * ans) % MOD << endl;
        } else {
            cout << 0 << endl;
        }
    }
}