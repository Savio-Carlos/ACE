#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int d1[]= {1, 0, -1, 0};
int d2[]= {0, 1, 0, -1};

signed main(){
    fastio;
    int n, m; 
    while(cin >> n >> m){
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int st = -1, fim = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'S'){
                    st = i;
                    fim = j;
                }
            }
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({st, fim});
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if(grid[x][y] >= '0' && grid[x][y] <= '9'){
                ans += grid[x][y] - '0';
            }
            vector<pair<int, int>> nxt;
            int pos = 1;
            for(int i = 0; i < 4; i++){
                int dx = d1[i] + x;
                int dy = d2[i] + y;
                if(dx < 0 || dx >= n) continue;
                if(dy < 0 || dy >= m) continue;
                if(grid[dx][dy] == 'T'){
                    pos = 0;
                    break;
                }else if(!visited[dx][dy] && grid[dx][dy] != '#'){
                    nxt.push_back({dx, dy});
                }
            }
            if(pos){
                for(auto [dx, dy] : nxt){
                    visited[dx][dy] = 1;
                    q.push({dx, dy});
                }
            }
        }

        cout << ans << endl;


    }
    

}