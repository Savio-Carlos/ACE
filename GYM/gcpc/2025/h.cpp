#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int MAX = 1e5+7;

set<int> r1, r2;
int visited[MAX][2];
vector<int> graph[MAX];

void dfs(int v, int p, int id){
    visited[v][id] = 1;
    if(id == 1) r1.insert(v);
    else r2.insert(v);

    for(auto u : graph[v]){
        if (visited[u][id]) continue;
        dfs(u,v,id); 
    }
}

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int a, b;
    cin >> a >> b;
    dfs(a,-1,1);
    dfs(b,-1,0);
    for(int i = 1; i <= n; i++){
        if(r1.count(i) && r2.count(i)){
            cout << "yes" << endl;
            cout << i << endl;            
            return 0;
        }
    }
    cout << "no" << endl;

}