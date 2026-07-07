#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

map<int, int> mp;

void factor(int x){
    for(int i = 2; i*i <= x; i++){
        if(!(x%i)){
            mp[i]++;
            while(!(x%i)) x/=i;
        }
    }
    if(x > 1){
        mp[x]++;
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i  =0; i < n; i++){
        int x; cin >> x;
        factor(x);
    }

    int mx = 0, ans = 0;
    for(auto [u, cnt] : mp){
        if(cnt > mx){
            mx = cnt;
            ans = u;
        }
    }
    cout << ans << endl;
}