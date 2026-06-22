#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;

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
    auto primos = brimos(MAX);

    vector<int> pfx, prime_cnt;
    int cur = 0;
    int cur_cnt = 0;
    for (int i = 0; i < MAX; i++){
        if (is_prime[i]){
            cur = (cur + i) % MOD;
            cur_cnt++;
        } 
        pfx.push_back(cur);
        prime_cnt.push_back(cur_cnt);
    }

    vector<int> pfx_duplas, duplas_cnt;
    cur = 0;
    cur_cnt = 0;
    for(int i = 0; i < MAX; i++){
        if(i >= 3 && is_prime[i] && is_prime[i - 2]){
            cur = (cur + i) % MOD;
            cur_cnt++;  
        }
        pfx_duplas.push_back(cur);
        duplas_cnt.push_back(cur_cnt);
    }

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        if(k == 1){
            cout << n << endl;
        } 
        else if(k == 2){
            int ans = 0;
            if (n >= 2) ans = (((n*prime_cnt[n]) % MOD) - pfx[n] + MOD) % MOD;

            // for(int i = 0; i < primos.size() && primos[i] <= n; i++){
            //     ans += n - primos[i];
            //     ans %= MOD;
            // }
            cout << ans << endl;

        } else if (k == 3){
            int ans = 0;
            // debug(n);
            // debug(duplas_cnt[n]);
            // debug(pfx_duplas[n]);
            if (n >= 5) ans = (((n*duplas_cnt[n]) % MOD) - pfx_duplas[n] + MOD) % MOD;
            // for(int i = 0; i < primos.size(); i++){
            //     if(is_prime[primos[i] + 2]){
            //         if(n - primos[i] - 2 > 0) ans += n - primos[i] - 2 + MOD;
            //         ans %= MOD;
            //     }
            // }
            cout << (2 * ans) % MOD << endl;
        } 
        else if (k == 4){
            int ans = 0;
            if (n > 7) ans = n-7;
            cout << (ans) % MOD << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}