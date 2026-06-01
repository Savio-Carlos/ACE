#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1};
int n;

vector<string> grid;

bool check(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int cur = 0;
int ans = 0;

void dfs(int x, int y){
    for (int i = 0; i < 4; i++){
        int novox = x + 2*dx[i];
        int novoy = y + 2*dy[i];
        int midx = x + dx[i];
        int midy = y + dy[i];
        
        if (check(novox, novoy)){
            if (grid[novox][novoy] == '.' && grid[midx][midy] == 'P'){
                grid[novox][novoy] = 'B';
                grid[midx][midy] = '.';
                grid[x][y] = '.';
                cur++;
                ans = max(ans,cur);
                dfs(novox, novoy);
                cur--;
                grid[novox][novoy] = '.';
                grid[midx][midy] = 'P';
                grid[x][y] = 'B';
            }
        }
    }
}

signed main(){
    fastio;

    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 'B'){
                dfs(i,j);
            } 
        }    
    }
    cout << ans << endl;
}