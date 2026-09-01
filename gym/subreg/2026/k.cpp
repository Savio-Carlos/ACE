#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
    }

    for(int i = 0; i < n; i++){
        cin >> v[i].second;
    }

    bool possivel = true;
    for(int i = 0; i < n; i++){
        if(v[i].first < v[i].second) possivel = false;
    }

    if(!possivel){
        cout << -1 << endl;
        return 0;
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        total += v[i].first;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, total - v[i].first + v[i].second);
    }

    cout << ans << endl;
}