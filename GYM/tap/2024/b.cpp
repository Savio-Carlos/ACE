#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    set<int> divisors;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            divisors.insert(i);
            if(i * i != n) divisors.insert(n/i);
        }
    }
    if (!divisors.size()){
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;   
    }

    vector<int> rem;
    for(auto u : divisors){
        for(auto v : divisors){
            if(u == v) continue;
            if((u%v) == 0) rem.push_back(v);
        }
    }

    for(auto u : rem){
        divisors.erase(u);
    }
    
    cout << divisors.size() << endl;
    for(auto u : divisors){
        cout << 1 << " " << u << endl;
    }
}