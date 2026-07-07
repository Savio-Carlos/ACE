#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

const int MAX = 1e6+7;

int n, spf[MAX];

void build(){
    for (int i = 2; i < MAX; i+= 2) spf[i] = 2;
    for (int i = 3; i < MAX; i+= 2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j * i < MAX; j += 2){
                if(spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

vector<int> factorize(int x){
    vector<int> primes;
    if (x == 1){
        primes.push_back(1);
        return primes;
    }
    while(x > 1){
        int p = spf[x];
        while (x%p == 0){
            primes.push_back(p);
            x/= p;
        }
    }
    return primes;
}

signed main(){
    fastio;
    build();
    
    int q;
    cin >> n >> q;
    vector<pair<int,vector<int>>> fatores;
    for (int i = 1; i <= n; i++){
        fatores.push_back({i, factorize(i)});
    }
    sort(all(fatores), [](const auto& b, const auto& c){ return b.second < c.second; });

    vector<int> ans(n+1);
    for (int i = 0; i < n; i++){
        ans[i+1] = fatores[i].first;
        
        // cout << "num: " << fatores[i].first << " vetor: ";
        // for (auto u : fatores[i].second) cout << u << " ";
        // cout << endl; 
    }

    while(q--){
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }
}