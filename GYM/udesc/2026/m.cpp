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

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int color[MAXN];

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    map<pair<int, int>, int> contr;
    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }else contr[{x, y}]++;
    }
    auto bfs = [&](int x, int c) -> bool {
        color[x] = c;
        queue<int> pq;
        pq.push(x);
        bool pos = true;
        while(!pq.empty()){
            auto v = pq.front(); pq.pop();
            for(auto u : graph[v]){
                if(color[u] == 0){
                    color[u] = c;
                    pq.push(u);
                }else if(color[u] != 0 && color[u] != color[v]){
                   pos = false;
                   break;
                }
            }
            if(!pos) break;
        }
        return pos;
    };
    for(auto [p, c] : contr){
        auto [a, b] = p;
        if(color[a] != 0 && color[a] == color[b]){
            cout << -1 << endl;
            return 0;
        }else if(color[a] == 0 && color[b] == 0){
            if(!bfs(a, 1)){
                cout << -1 << endl;
                return 0;
            }
            if(!bfs(b, 2)){
                cout << -1 << endl;
                return 0;
            }
        }else{
            int c1 = color[a];
            int c2 = color[b];
            if(color[a] == 0) c1 = color[b] == 1 ? 2 : 1;
            if(color[b] == 0) c2 = color[a] == 1 ? 2 : 1;
            if(!bfs(a, c1)){
                cout << -1 << endl;
                return 0;
            }
            if(!bfs(b, c2)){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    

    for(int i = 1; i <= n; i++){
        if(color[i] == 0) color[i] = 1;
        cout << color[i] << " ";
    }
    cout << endl;
}