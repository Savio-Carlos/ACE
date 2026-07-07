#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define ld long double

const int MAX = 1e7+3;
int n, spf[MAX];
int cnt[MAX];

void build(){
    for (int i = 2; i < MAX; i+= 2) spf[i] = 2;
    for (int i = 3; i < MAX; i+= 2){
        if(!spf[i]){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+= 2){
                if(spf[i*j]==0) spf[i*j] = i;
            }
        }
    }
}

void fator(int x){
    while(x > 1){
        int p = spf[x];
        while(x%p == 0){
            x/=p;
            cnt[p]++;
        }
    }
}

signed main(){
    fastio;
    build();
    // int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a){
        cin >> u;
        fator(u);
    } 
    vector<int> vals;
    for (int i = 1; i < MAX; i++){
        if(cnt[i]) vals.push_back(i*cnt[i]);
    }
    sort(rall(vals));
    int ans = 0;
    for (int i = 0; i < vals.size(); i+=2){
        ans += vals[i];
    }
    cout << ans << endl;
    
}