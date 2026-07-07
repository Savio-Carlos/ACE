#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &u: grid) cin >> u;
    
    vector<vector<int>> cima(n ,vector<int>(m, 0));
    vector<vector<int>> direita(n ,vector<int>(m, 0));//quantas letras iguais em sequencia pra cima e pra direita
    

    auto check = [&](int x, int y) -> bool{
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    for (int i = 0; i < n; i++){
        int cur = 0;
        for (int j = m-2; j >= 0; j--){
            if (grid[i][j] == grid[i][j+1]) cur++;
            else cur = 0;
            direita[i][j] = cur;
        }
    }

    for (int j = 0; j < m; j++){
        int cur = 0;
        for (int i = 1; i < n; i++){
            if (grid[i][j] == grid[i-1][j]) cur++;
            else cur = 0;
            cima[i][j] = cur;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // debug(i);
            // debug(j);
            // debug(cima[i][j]);
            // debug(direita[i][j]);
            ans += cima[i][j]*direita[i][j];
        }
    }
    cout << ans << endl;
}