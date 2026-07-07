#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAXN = 1e5+7;
const int MOD = 1e9+7;
vector<int> graph[MAXN];
int visited[MAXN];
int c = 0;

void dfs(int v){
    visited[v] = 1;
    c++;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            c = 0;
            dfs(i);
            ans = (ans * c)%MOD;
        }
    }

    cout << ans << endl;

}