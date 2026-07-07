#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

vector<pair<int,int>> dt = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{-4,1},{-4,-1}};
vector<pair<int,int>> da = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{-4,1},{-0,2},{-1,2},{-2,2},{-2,1},{-3,2},{-4,2}};
vector<pair<int,int>> dp = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{-4,1},{-2,2},{-2,1},{-3,2},{-4,2}};

int stop = 0;

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    auto check = [&](int x, int y) -> bool{
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    auto eht = [&](int x, int y) -> bool{

        for (auto [dx,dy] : dt){
            stop++;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) return false;
            if(visited[nx][ny]) return false;
            if (grid[nx][ny] != '#') return false;
            visited[nx][ny] = true;
        }
        return true;
    };
    auto eha = [&](int x, int y) -> bool{
        for (auto [dx,dy] : da){
            stop++;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) return false;
            if(visited[nx][ny]) return false;
            if (grid[nx][ny] != '#') return false;
            visited[nx][ny] = true;
        }
        return true;
    };
    auto ehp = [&](int x, int y) -> bool{
        for (auto [dx,dy] : dp){
            stop++;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) return false;
            if(visited[nx][ny]) return false;
            if (grid[nx][ny] != '#') return false;
            visited[nx][ny] = true;
        }
        return true;
    };


    //desmarcar todos visitados
    auto uncheckt = [&](int x, int y) -> void{
        for (auto [dx,dy] : dt){
            stop--;
            if (!stop) return;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) continue;;
            visited[nx][ny] = false;
        }
    };
    auto unchecka = [&](int x, int y) -> void{
        for (auto [dx,dy] : da){
            stop--;
            if (!stop) return;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) continue;;
            visited[nx][ny] = false;
        }
    };
    auto uncheckp = [&](int x, int y) -> void{
        for (auto [dx,dy] : dp){
            stop--;
            if (!stop) return;
            int nx = x + dx;
            int ny = y + dy;
            if (!check(nx,ny)) continue;;
            visited[nx][ny] = false;
        }
    };

    int cnta = 0, cntt = 0, cntp = 0;

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < m; j++){
            bool found = false;
            stop = 0;

            if (eha(i,j)){
                found = true;
                cnta++;
                // cout << "aaa" << endl;
            } 
            else if(!found){
                unchecka(i,j);
            }
            if (found) continue;
            
            stop = 0;
            if (!found && ehp(i,j)){
                cntp++;
                found = true;
                // cout << "ppp"<< endl;
            } 
            else if(!found){
                uncheckp(i,j);
            }
             
            stop = 0;
            if (!found && eht(i,j)){
                cntt++;
                found = true;
            } 
            else if(!found){
                uncheckt(i,j);
            }


            // if(found){
            //     for(int i = 0; i < n; i++){
            //         for(int j = 0; j < m; j++){ 
            //             cout << visited[i][j];
            //         } cout << endl;
            //     } cout << endl;
            // }
            if (found) continue;
        }
    }

    cout << cntt << " " << cnta << " " << cntp << endl;
}