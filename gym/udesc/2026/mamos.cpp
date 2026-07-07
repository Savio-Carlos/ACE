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

int n, m;

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> arestas(n);
    vector<int> tipe(n, -1);
    vector<bool> visited(n);
    for(int i = 0; i < m; i++){
        int t, a, b;
        cin >> t >> a >> b;
        arestas[a-1].push_back({b-1,t});
        arestas[b-1].push_back({a-1,t});
    }

    bool con = false;
    for(int i = 0; i < n; i++){

        queue<int> q;

        if(!visited[i]){

            q.push(i);
            visited[i] = true;
            tipe[i] = 1;

            while(!q.empty()){

                int atual = q.front();
                q.pop();

                for(auto &[prox, t]:arestas[atual]){

                    if(!visited[prox]){
                        q.push(prox);
                        visited[prox] = true;
                        if(t == 1)  tipe[prox] = tipe[atual];
                        else tipe[prox] = !tipe[atual];
                    }

                    if(t == 1 && tipe[prox] != tipe[atual]) con = true;
                    if(t == 2 && tipe[prox] == tipe[atual]) con = true;
                }
            }
        }
    }
    if(con) cout << "-1" << endl;
    else {
        for(int i = 0; i < n; i++){
            if(tipe[i] == 0) cout << 2 << " ";
            if(tipe[i] == 1) cout << 1 << " ";
        }
        cout << endl;
    }
}