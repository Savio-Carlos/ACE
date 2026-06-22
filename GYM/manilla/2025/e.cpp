#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve(){
    int r,c;
    cin>>r>>c;
    vector<string> A(r);
    for(auto &u:A)cin>>u;

    vector<string> B(r);
    for(auto &u:B)cin>>u;

    pair<int,int> sta, stb, en;

    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            if(A[i][j] == 'S') sta = {i, j};
        }
    }
    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            if(B[i][j] == 'S') stb = {i, j};
            if(B[i][j] == 'D') en = {i, j};
        }
    }

    int state[r][c][r][c];

    vector<vector<int>> dist(r, vector<int>(c, 1e9));

    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            for(int k=0; k < r; k++){
                for(int l=0; l < c; l++){
                    state[i][j][k][l] = 1e9;
                }
            }
        }   
    }

    auto check = [&](int x, int y)->bool{
        return (x>=0 && x<r && y>=0 && y<c);
    };

    priority_queue<tuple<int,int,int,int,int>> pq;
    pq.push({0, sta.first, sta.second, stb.first, stb.second});
    dist[stb.first][stb.second] = 0;
    state[sta.first][sta.second][stb.first][stb.second] = 0;

    while(!pq.empty()){
        auto [d, xa, ya, xb, yb] = pq.top();
        tuple<int,int,int,int> cur = {xa,ya,xb,yb};
        d = -d;
        pq.pop();
        if (d != state[xa][ya][xb][yb]) continue;
        
        for (int i =0; i <4; i++){
            int nxa = xa + dx[i];
            int nya = ya + dy[i];
            if(!check(nxa,nya) || A[nxa][nya] == 'X')continue;

            int nxb = xb + dx[i];
            int nyb = yb + dy[i];
            if(!check(nxb,nyb) or B[nxb][nyb] == 'X'){
                nxb = xb;
                nyb =yb;
            }

            int nd=d+1;
            if (dist[nxb][nyb] > nd) dist[nxb][nyb]=nd;
            if(state[nxa][nya][nxb][nyb] > nd){

                // cout << "nxa,nya,nxb,nyb,nd: " << nxa << " " << nya<<" " << nxb << " " << nyb << " " << nd << endl;
                state[nxa][nya][nxb][nyb] = nd;
                pq.push({-nd,nxa,nya,nxb,nyb});
            }
        }
    }
    if (dist[en.first][en.second] == 1e9) cout <<-1<<endl; 
    else cout <<dist[en.first][en.second] <<endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--)solve();
}