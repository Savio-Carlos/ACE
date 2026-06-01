#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int dx[] = {-1,1,0,0,0};
int dy[] = {0,0,1,-1,0};

signed main(){
    fastio;
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){    
            cin >> grid[i][j];
        }
    }
    vector<pair<int,int>> giovana(t);
    vector<pair<int,int>> artur(t);

    auto check = [&](int x, int y) -> bool{
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    for (auto &[u,v] : giovana) cin >> u >> v;
    for (auto &[u,v] : artur) cin >> u >> v;
    int g = 0;
    int a = 0;

    for (int tempo = 0; tempo < t; tempo++){
        auto [gi, gj] = giovana[tempo];
        auto [ai, aj] = artur[tempo];  
        
        gi--;
        gj--;
        ai--;
        aj--;

        for (int i = 0; i < 5; i++){
            int nxg = gi+dx[i];
            int nyg = gj+dy[i];
            int nxa = ai+dx[i];
            int nya = aj+dy[i];

            if (check(nxg, nyg)){
                visited[nxg][nyg]++;
            }
            if (check(nxa, nya)){
                visited[nxa][nya]++;
            }
        }

        for (int i = 0; i < 5; i++){
            int nxg = gi+dx[i];
            int nyg = gj+dy[i];
            int nxa = ai+dx[i];
            int nya = aj+dy[i];

            if (check(nxg, nyg)){
                if (visited[nxg][nyg] == 1){
                    g += grid[nxg][nyg];
                    grid[nxg][nyg] = 0;
                }
            }
            if (check(nxa, nya)){
                if (visited[nxa][nya] == 1){
                    a += grid[nxa][nya];
                    grid[nxa][nya] = 0;
                }
            }
        }

        for (int i = 0; i < 5; i++){
            int nxg = gi+dx[i];
            int nyg = gj+dy[i];
            int nxa = ai+dx[i];
            int nya = aj+dy[i];

            if (check(nxg, nyg)){
                visited[nxg][nyg] = 0;
            }
            if (check(nxa, nya)){
                visited[nxa][nya] = 0;
            }
        }
        // cout << g << " - " << a << endl;
    }
    cout << g << " " << a << endl;
}