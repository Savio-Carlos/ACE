#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 510;
int graph[MAXN][MAXN];
int n, m, u1, v1, u2, v2;

int d1[4] = {0, 1, 0, -1};
int d2[4] = {1, 0, -1, 0}; 

bool check(int mid){
    for(int i = u1; i <= u2; i++){
        for(int j = v1; j <= v2; j++){
            if(graph[i][j] > mid) return false;
        }
    }

    int empty = 0, r = 0;
    queue<pair<int, int>> q;
    q.push({u1, v1});
    vector<vector<int>>visited(n+1, vector<int>(m+1, 0));
    visited[u1][v1] = 1;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(graph[x][y] == 0) empty++;
        if(x >= u1 && x <= u2 && y >= v1 && y <= v2) r++;
        for(int i = 0; i < 4; i++){
            int dx = d1[i] + x;
            int dy = d2[i] + y;
            if(dx < 1 || dx > n) continue;
            if(dy < 1 || dy > m) continue;

            if(!visited[dx][dy] && graph[dx][dy] <= mid){
                visited[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
    }   

    return r <= empty;
}

void solve(){
    int k; cin >> n >> m >> k;
    //cout << n << " " << m << " " << k << endl;
    for(int i = 1; i <= k; i++){
        int a, b; cin >> a >> b;
        graph[a][b] = i;
    }

    cin >> u1 >> v1 >> u2 >> v2;
    int l = 0, r = k, ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    cout << ans << endl;
}

signed main() {
    fastio;
    int t;
    t= 1;
    while(t--){
        solve();
    }
}