#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    map<int, int> R, D;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        R[x]++;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        D[x]++;
    }

    int ric = 0, dan = 0;
    for(auto [val,r]:R){
        if(r > 1 && !D.count(val)) ric++;
    }

    for(auto [val,d]:D){
        if(d > 1 && !R.count(val)) dan++;
    }

    cout << min(ric, dan) << endl;

}