#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    // fastio;
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));

    int ans = 0;
    stack<pair<int,int>> stk;
    for(int i = 0; i < n; i++){
        while(!stk.empty() && stk.top().first < v[i].first && stk.top().second > v[i].second){
            stk.pop();
        }
        stk.push(v[i]);
        ans = max(ans, (int)stk.size());
    }
    cout << ans << endl;

}