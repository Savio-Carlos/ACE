#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cerr << #x << ": " << x << endl;

const int INF = 1e9+7;

struct Dinic {
    struct edge { 
        int to, cap, rev, flow, cost;
        bool res; 
        edge(int to_, int cap_, int rev_, bool res_, int cost_) : to(to_), cap(cap_), rev(rev_), flow(0), res(res_), cost(cost_) {}
    };
    vector<vector<edge>> graph;
    vector<int> level, beg;
    int n;
    int fluxo;
 
    Dinic(int n) : n(n), graph(n), level(n), beg(n), fluxo(0) {}
 
    void add(int a, int b, int c, int w) {
        graph[a].emplace_back(b, c, (int)graph[b].size(), false, w);
        graph[b].emplace_back(a, 0, (int)graph[a].size() - 1, true, 0);
    }
 
    bool bfs(int s, int t, int k) {
        fill(level.begin(), level.end(), -1);
        fill(beg.begin(), beg.end(), 0);
        level[s] = 0; 
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &e : graph[u]){
                if (e.cost > k) continue;
                if (level[e.to] != -1 or (e.flow == e.cap)) continue;
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
                
        }
        return level[t] >= 0;
    }
 
    int dfs(int v, int t, int k, int f = INF) {
        if (v == t or !f) return f;
 
        for (int &i = beg[v]; i < (int)graph[v].size(); i++) {
            auto &e = graph[v][i];
            if (e.cost > k) continue;
            if (level[e.to] != level[v] + 1) continue;
            
            int d = dfs(e.to, t, k, min(f, e.cap - e.flow));
            
            if (!d) continue; 
            e.flow += d;
            graph[e.to][e.rev].flow -= d;
            return d;
            }
        return 0;
    }
 
    int max_flow(int s, int t, int k) {
        fluxo = 0;
        while (bfs(s, t, k)) {
            while (int f = dfs(s, t, k)) fluxo += f;
        }
        return fluxo;
    }
 
};

signed main(){
    fastio;
    int p, r, c;
    cin >> p >> r >> c;
    int sum = 0;
    int n = p+r+2;
    int source = 0, sink = n-1;

    vector<int> pp(p), rr(r);
    for (auto &u : pp) {cin >> u; sum += u;}
    for (auto &u : rr) cin >> u;
     
    vector<tuple<int,int,int>> edges(c);
    
    for (auto &[u,v,w] : edges){
        cin >> u >> v >> w;           
    } 
    
    auto check = [&](int mid) -> bool{
        Dinic dinic(n);
        for (int i = 1; i <= p; i++){
            dinic.add(i, sink, pp[i-1], 0);
        }
        for (int i = 1; i <= r; i++){
            dinic.add(source, p+i, rr[i-1], 0);
        }
        
        for (auto &[u,v,w] : edges){
            if (w <= mid) dinic.add(p+v,u,INF,w);             
        } 

        int aux = dinic.max_flow(source, sink, mid);
        // debug(mid);
        // debug(aux);
        return (aux == sum);
    };

    int ans = -1;
    int l = 0, hi = 1e6+1;
    while (l <= hi){
        int mid = (l + hi) / 2;
        if (check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}