#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> dist(n, vector<int>(m, 1e12));

    for (auto &s : grid) cin >> s;
    pair<int,int> st, en;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'S') st = {i,j};
            if (grid[i][j] == 'E') en = {i,j};
        }
    }
    auto check = [&](int x, int y) -> bool{
        return (x < n && x >= 0 && y >= 0 && y < m && grid[x][y] != '#');
    };
    queue<pair<int,int>> q;
    q.push(st);
    dist[st.first][st.second] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx,ny) && dist[nx][ny] > (dist[x][y] + 1)){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << i << " " << j << " " << dist[i][j] << endl;;
    //     }
    // }
    // cout << endl;

    if (dist[en.first][en.second] == 1e12) cout << -1 << endl; 
    else cout << dist[en.first][en.second] << endl;
    
}