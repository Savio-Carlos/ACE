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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> pos;
    vector<pair<int,int>> idx;
    for (int i = 0; i < n; i++){
        int u;
        char c;
        cin >> u >> c;
        idx.push_back({u,i});
        pos.push_back(u + (c == 'E' ? -t : t));
    }
    sort(all(idx));
    sort(all(pos));
    vector<int> ans(n);
    for (int i = 0 ; i < n; i++){
        auto res = pos[i];
        auto p = idx[i].second;
        ans[p] = res;
    }
    for (auto res : ans){
        if (res <= 0) cout << "ESQUERDA\n";
        else if (res >= m) cout << "DIREITA\n";
        else cout << res << endl;
    }
        
}