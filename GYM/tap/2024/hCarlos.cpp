#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    constexpr const char* RESET      = "\033[0m";
    constexpr const char* BOLD_BLUE  = "\033[1;34m";
    constexpr const char* YELLOW     = "\033[33m";
    constexpr const char* BOLD_WHITE = "\033[1;37m";

    template<typename T, typename = void> struct is_container : false_type {};
    template<typename T> struct is_container<T, void_t<typename T::value_type>> : bool_constant<!is_same_v<T, string> && !is_same_v<T, string_view>> {};

    inline ostream& print_atom(ostream& os, bool b)         { return os << (b ? "true" : "false"); }
    inline ostream& print_atom(ostream& os, char c)         { return os << '\'' << c << '\''; }
    inline ostream& print_atom(ostream& os, const string& s){ return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, string_view s)  { return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, const char* s)  { return os << '"' << s << '"'; }

    template<typename T, enable_if_t<!is_container<T>::value, int> = 0>
    ostream& print_atom(ostream& os, const T& x) { return os << x; }

    template<typename T1, typename T2>
    ostream& print_atom(ostream& os, const pair<T1, T2>& p) {
        os << '{'; print_atom(os, p.first); os << ", "; print_atom(os, p.second); return os << '}';
    }
    template<typename... T>
    ostream& print_atom(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((print_atom(os, args), os << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
        return os << '}';
    }

    template<typename T, typename C>
    ostream& print_atom(ostream& os, stack<T, C> s) {
        os << '{'; bool f = true; while (!s.empty()) { if (!f) os << ", "; print_atom(os, s.top()); s.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C>
    ostream& print_atom(ostream& os, queue<T, C> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.front()); q.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C, typename Cmp>
    ostream& print_atom(ostream& os, priority_queue<T, C, Cmp> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.top()); q.pop(); f = false; } return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& print_atom(ostream& os, const C& v) {
        os << '{'; bool f = true;
        for (const auto& x : v) { if (!f) os << ", "; print_atom(os, x); f = false; }
        return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& operator<<(ostream& os, const C& v)            { return print_atom(os, v); }
    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return print_atom(os, p); }
    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t)  { return print_atom(os, t); }

    inline size_t split_arg(string_view s) {
        int depth = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '"' || c == '\'') {
                char q = c; ++i;
                while (i < s.size() && s[i] != q) { if (s[i] == '\\' && i + 1 < s.size()) ++i; ++i; }
            } else if (c == '(' || c == '[' || c == '{' || c == '<') ++depth;
            else if (c == ')' || c == ']' || c == '}' || c == '>') --depth;
            else if (c == ',' && depth == 0) return i;
        }
        return string_view::npos;
    }

    inline void debug_out(string_view) { cerr << '\n' << flush; }
    template<typename H, typename... T>
    void debug_out(string_view s, const H& h, const T&... t) {
        size_t cpos = split_arg(s);
        auto name = s.substr(0, cpos);
        while (!name.empty() && (name.front() == ' ' || name.front() == '\t')) name.remove_prefix(1);
        while (!name.empty() && (name.back()  == ' ' || name.back()  == '\t')) name.remove_suffix(1);
        cerr << YELLOW << name << RESET << " = " << BOLD_WHITE;
        print_atom(cerr, h) << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            debug_out(cpos == string_view::npos ? string_view{} : s.substr(cpos + 1), t...);
        } 
        else cerr << '\n' << flush;
    }
}
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) do { cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "] " << RESET; dbg::debug_out(#__VA_ARGS__, __VA_ARGS__); } while (0)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) ((void)0)
#endif


enum type {
    PARACHUTE,
    INSERT,
    REMOVE,
};

enum borda{
    BOTTOM, 
    TOP
};   

struct event{
    int x1, y1;
    int x2, y2;
    int id;
    type t;
    bool operator<(const event& o) const {
        return x1 < o.x1;
    }
};

signed main(){
    winton;
    int n, m;
    cin >> n >> m;

    map<int, vector<event>> mp;

    for (int i = 1; i <= n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mp[x1].push_back({x1,y1,x2,y2,i,INSERT});
        mp[x2].push_back({x1,y1,x2,y2,i,REMOVE});
    }
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        event temp;
        temp.x1 = x;
        temp.y1 = y;
        temp.id = i;
        temp.t = PARACHUTE;
        mp[x].push_back(temp);
    }

    vector<int> cnt(n+1, 0), parent(n+1, 0);
    //cnt = quantos paraquedas dentro dessa cerca
    vector<vector<int>> graph(n+1);
    
    set<tuple<int,int,borda>> st; //y, id, tipo
    for (auto &[x, events] : mp){

        for (auto [x1,y1,x2,y2,id,tipo] : events){
            
            if (tipo == INSERT){
                //inserir uma cerca, vejo quem eo pai dela (upperbound e vejo se e top or bottom)
                //preciso colocar no grafo
                auto it = st.upper_bound({y2,-1,BOTTOM});//ESSE bottom aqui vai dar problema sera?
                if (it != st.end()){
                    auto [_, p, b] = *it;
                    if (b == TOP){
                        parent[id] = p;
                        graph[p].push_back(id);
                    }
                    else {
                        parent[id] = parent[p];
                        graph[parent[p]].push_back(id);
                    }
                }
                else {
                    graph[0].push_back(id);
                }
                st.insert({y1,id,BOTTOM});
                st.insert({y2,id,TOP});
            }
            else if (tipo == REMOVE){
                auto it = st.find({y1,id,BOTTOM});
                st.erase(it);
                it = st.find({y2,id,TOP});
                st.erase(it);
            }
            else if (tipo == PARACHUTE){
                //e um paraquedas, quero ver qual no ele pertence e aumentar o cnt daquele no
                auto it = st.upper_bound({y1,-1,BOTTOM});
                if (it != st.end()){
                    auto [_, p, b] = *it;
                    if (b == TOP)cnt[p]++;
                    else cnt[parent[p]]++;
                }
                else cnt[0]++;
            }
        }
    }

    ld ans = 0;
    vector<int> dp(n+1, 0);
    
    function<void(int, int)> dfs = [&] (int v, int p){
        dp[v] += cnt[v];
        for (auto u :graph[v]){
            if (u == v) continue; 
            dfs(u,v);
            dp[v] += dp[u];
        }
        ans += 2.0 * dp[v] * (m - dp[v]);
    };

    dfs(0,-1);
    ans /= (ld)(m*m);
    debug(ans);

    cout << fixed << setprecision(10) << ans << endl;
}