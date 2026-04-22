#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
 
void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    cerr << line << ": ";
    while (!s.empty() && s[0] == ' ') s = s.substr(1);
    int pos = 0;
    int bracket = 0;
    while (pos < (int)s.size() && (s[pos] != ',' || bracket > 0)) {
        if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{') bracket++;
        if (s[pos] == ')' || s[pos] == ']' || s[pos] == '}') bracket--;
        pos++;
    }
    cerr << s.substr(0, pos) << " = " << h;
    if (sizeof...(t)) cerr << " | ";
    debug_out(pos < (int)s.size() ? s.substr(pos + 1) : "", line, t...);
}
 
// #define DEBUG
 
#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;

    vector<vector<int>> children(n + 1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        children[p].push_back(i);
    }

    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;

    stack<pair<int,int>> stk;
    stk.push({1, 0});
    tin[1] = timer++;
    while(!stk.empty()){
        auto& [u, idx] = stk.top();
        if(idx < (int)children[u].size()){
            int v = children[u][idx++];
            tin[v] = timer++;
            stk.push({v, 0});
        } else {
            tout[u] = timer++;
            stk.pop();
        }
    }

    while(q--){
        int m;
        cin >> m;
        vector<int> s(m);
        for(int i = 0; i < m; i++) cin >> s[i];

        sort(all(s), [&](int a, int b){
            return tin[a] < tin[b];
        });

        int cnt = 0;
        for(int i = 0; i + 1 < m; i++){
            if(tin[s[i]] <= tin[s[i+1]] && tout[s[i]] >= tout[s[i+1]]){
                cnt++;
            }
        }

        cout << m - cnt << endl;
    }
}