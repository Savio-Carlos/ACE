#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
using namespace dbg;

#define DEBUG

#ifdef DEBUG
    #define fastio (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int INF = 2e18;

struct Dinic {
    struct Edge { 
        int to, cap, rev; 
    };
    vector<vector<Edge>> graph;
    vector<int> level, beg;
    int n;

    Dinic(int n) : n(n), graph(n), level(n), beg(n) {}

    void add(int a, int b, int c) {
        graph[a].push_back({b, c, graph[b].size()});
        graph[b].push_back({a, 0, graph[a].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &e : graph[u])
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;

        for (int &i = beg[v]; i < graph[v].size(); i++) {
            Edge &e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(beg.begin(), beg.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};


int n, m;
vector<pair<int,int>> edges;

int solve(vector<int> sources, vector<int> sinks) {
    int s = n, t = n + 1;
    Dinic dinic(n+2);

    for (auto [u,v] : edges) {
        u--; v--;
        dinic.add(u, v, 1);
        dinic.add(v, u, 1);
    }

    for (auto so : sources) dinic.add(s, so-1, INF);
    for (auto si : sinks) dinic.add(si-1, t, INF);

    return dinic.max_flow(s, t);
}

signed main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int f1 = solve({a1, b1}, {a2, b2});
    int f2 = solve({a1, b2}, {a2, b1});

    cout << min(f1,f2) << endl;
}