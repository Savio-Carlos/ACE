#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 31;
const int INF = 1e9;

set<int> graph[MAX];

signed main(){
    fastio;
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> faladas(n+1);
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        vector<int> st;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            for(auto u : st){
                graph[x].insert(u);
                graph[u].insert(x);
            }
            st.push_back(x);
        }
        faladas[i] = st;
    }

    vector<vector<int>> dist(m+1, vector<int>(m+1, INF));
    //p todas as musicas
    for(int i = 1; i <= m; i++){
        priority_queue<pair<int, int>> pq;
        //dis, v;
        dist[i][i] = 0;
        pq.push({0,i});

        while(!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            d = -d;
            if(dist[i][v] < d) continue;
            for(auto u : graph[v]){
                if(dist[i][u] > d + 1){
                    dist[i][u] = d + 1;
                    pq.push({-dist[i][u], u});
                }
            }
        }

        // for(int j = 1; j <= m; j++) cout << dist[i][j] << " ";
        // cout << endl;
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        int ans = INF;
        for(auto u : faladas[a]){
            for(auto v : faladas[b]){
                ans = min(ans, dist[u][v]);
            }
        }
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}