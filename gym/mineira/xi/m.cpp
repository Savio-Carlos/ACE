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
    int q, n;
    int t;
    cin >> q >> n >> t;

    vector<pair<int,int>> questions(q);
    for (auto &[u, v] : questions) cin >> u >> v;

    vector<pair<int,int>> students(n);
    for(int i = 0; i < n; i++){
        cin >> students[i].first;
        students[i].second = i;
    }

    sort(all(questions));
    sort(all(students));

    multiset<int> times;
    int soma = 0;
    int ptr = 0;
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        auto [ci, idx] = students[i];

        while(ptr < q && questions[ptr].first <= ci){
            int ti = questions[ptr].second;
            times.insert(ti);
            soma += ti;
            ptr++;
        }

        while(soma > t && !times.empty()){
            auto it = prev(times.end());
            soma -= *it;
            times.erase(it);
        }

        ans[idx] = times.size();
    }

    for (auto u : ans) cout << u << endl;
}