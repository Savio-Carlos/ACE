#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

vector<int> factor(int n){
    vector<int> primes;
    for (int p = 2; p * p <= n; p++){
        while(n%p == 0){
            primes.push_back(p);
            n /= p;
        }
    }
    if (n > 1) primes.push_back(n);
    return primes;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    auto fatores = factor(n);
    int m = fatores.size();
    for (int i = 0; i < m; i++){
        cout << fatores[i] << "x\n"[i+1==m];
    }
}