#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

const int MAX = 105;

signed main(){
    fastio;
    
    vector<vector<int>> grid(MAX+1, vector<int>(MAX+1,0));
    for (int i = 1; i <= MAX; i++){
        for (int j = 1; j <= MAX; j++){
            if (i == j) continue;
            int mex = 0;
            set<int> s;
            
            for (int r = i-1; r; r--){
                if (r == j) continue;
                s.insert(grid[r][j]);
            }
            
            for (int c = j-1; c; c--){
                if (c == i) continue;
                s.insert(grid[i][c]);
            }
            
            for (int r = i-1, c = j-1; r and c; r--, c--){
                s.insert(grid[r][c]);
            }

            while(s.find(mex) != s.end())mex++;
            grid[i][j] = mex;
        }
    }
    
    int n;
    cin >> n;
    bool can_in_one = false;
    int xr = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (!x or !y or x == y){
            can_in_one = 1;
            break;
        } 
        
        xr ^= grid[x][y];
    }   

    if (can_in_one or xr) cout << "Y" << endl;
    else cout << "N" << endl;
}