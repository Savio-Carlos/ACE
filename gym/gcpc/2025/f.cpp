#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    fastio;
    int h , w;
    cin >> h >> w;
    int tot = 0;
    vector<string> grid(h);
    for (int i = 0; i < h; i++){
        cin >> grid[i];
        for (auto c : grid[i]) if(c == '#') tot++;
    }
    
    
    vector<int> divisors;
    for (int i = 1; i * i <= tot; ++i) {
        if (tot % i == 0) {
            divisors.push_back(i);
            if (i * i != tot) divisors.push_back(tot / i);
        }
    }

    vector<vector<int>> original(h, vector<int>(w, 0));
    auto visited = original;

    auto check = [&](int i, int j, int u) -> bool{
        for (int ii = i; ii < i+u; ii++){
            for (int jj = j; jj < j+u; jj++){
                if (ii >= h || jj >= w) return false;
                if(visited[ii][jj]) return false;
                visited[ii][jj] = 1;
                if(grid[ii][jj] == '.') return false;
            }
        }
        return true;i
    };

    int ans = 1;
     for (int u = 2; u <= 2500; u++){
        if (tot%(u*u) != 0) continue;
        // cout << u << endl;
        visited = original;

        bool pos = true;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if(visited[i][j]) continue;
                if (grid[i][j] == '#'){
                    if(check(i,j,u)) continue;
                    else pos = false;
                }
            }
        }
        if(pos) ans = u;
    } 

    cout << ans << endl;


}