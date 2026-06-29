#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 1e2+7;
const int INF = 1e15;
int n; 
int grid[MAX][MAX];

int check(int st, int en){
    int dist[MAX];
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i] = INF;
        }
    }
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[v]) continue;
        for(int u = 0; u < n; u++){
            if (v == u) continue;
            int nd = d + grid[v][u];
            if (nd < dist[u]){
                dist[u] = nd;
                pq.push({-nd, u});
            }
        }
    }

    return dist[en];
}

signed main(){
    fastio; 
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    bool pos = true;
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int prev = grid[i][j];
            grid[i][j] = INF;
            grid[j][i] = INF;
            int x = check(i, j);
            // debug(i);
            // debug(j);
            // debug(x);
            // debug(grid[i][j]);
            if (x < prev){
                pos = false;
                break;
            }
            else if (x == prev){
                ans++;
            }
            else {
                grid[i][j] = prev;
                grid[j][i] = prev;
            }

        }
    }



    if(!pos) cout << -1 << endl;
    else cout << ans << endl;
}