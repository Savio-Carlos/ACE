#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define debug(x) cerr << #x << ": " << x << endl;

struct DSU{

    vector<int> id, sz;
    DSU(int n) : id(n), sz(n,1) { iota(id.begin(), id.end(), 0);}
    int find(int x) {return x == id[x] ? x : id[x] = find(id[x]);}
    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        id[b] = a;
        return true;
    }
     
};

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dsu.unite(a,b);
    }

    vector<pair<int,int>> ans;
    set<pair<int,int>> rank;
    vector<vector<int>> grupo(n);

    for (int i = 0; i < n; i++){
        grupo[dsu.id[i]].push_back(i);
    }

    for (int i = 0; i < n; i++){
        int s = grupo[i].size();
        if (s) {
            rank.insert({s,i});
            // cout << "grupo: " << i << " sz: " << s << endl;
        }
    }

    while (rank.size() > 1){
        auto prim = *rank.begin();
        auto ult = *rank.rbegin();

        rank.erase(prim);
        rank.erase(ult);

        int p = prim.second;
        int u = ult.second;

        ans.push_back({grupo[p].back(), grupo[u].back()});
        grupo[p].pop_back();
        grupo[u].pop_back();

        if(grupo[p].size())rank.insert({grupo[p].size(),p});
        if(grupo[u].size())rank.insert({grupo[u].size(),u});
    }

    cout << ans.size() << endl;
    for (auto [u,v] : ans) cout << u << " " << v << endl;

}