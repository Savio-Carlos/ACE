#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

const int INF = 1e18+7;
const int MAXN = 2e5+7;
vector<tuple<int, int, int>> graph[MAXN];

signed main(){
    fastio;
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, a, b; cin >> u >> v >> a >> b;
        if(b == -1) b = INF;
        graph[u].push_back({v, a, b});
        graph[v].push_back({u, a, b});
    }

    //DIST, QTD, V 
    priority_queue<tuple<int, int, int>> pq;
    vector<vector<int>> dist(n+1, vector<int>(11, INF));
    dist[1][0] = 0;
    pq.push({0, 0, 1});
    while(!pq.empty()){
        auto [dis, qtd, v] = pq.top(); pq.pop();
        dis = -dis;
        if(dist[v][qtd] < dis) continue;
        for(auto [u, a, b] : graph[v]){
            if(qtd + 1 <= k && dist[u][qtd+1] > dis + b){
                dist[u][qtd+1] = dis + b;
                pq.push({-dist[u][qtd+1], qtd+1, u});
            }if(dist[u][qtd] > dis + a){
                dist[u][qtd] = dis + a;
                pq.push({-dist[u][qtd], qtd, u});
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= k; i++){
        //cout << dist[n][i] << " ";
        ans = min(dist[n][i], ans);
    }
    cout << ans << endl;
}