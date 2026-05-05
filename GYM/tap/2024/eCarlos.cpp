#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((os << args << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int INF = 1e18;

struct weapons{
    int a, b, c;
    friend ostream& operator<<(ostream& os, const weapons& w) {
        return os << '{' << w.a << ", " << w.b << ", " << w.c << '}';
    }
};

signed main(){
    winton;
    int n, p;
    cin >> n >> p;
    vector<vector<int>> dp(n, vector<int>(p+1, -1));
    vector<weapons> armas(n);
    for (auto &[a,b,c] : armas) cin >> a >> b >> c; 
    
    sort(all(armas), [&](auto i, auto j){
        return i.b + i.a * j.b < j.b + j.a * i.b;
    });

    debug(armas);

    function<int(int, int)> knapsack = [&](int i, int w) -> int {
        if (w < 0 ) return -INF;
        if (i == n) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        auto [a,b,c] = armas[i];
        ld custo = (ld)(w - b) / (ld)a;
        int nw = floor(custo);
        debug(i, custo, c, nw);
        return dp[i][w] = max(knapsack(i+1, nw) + c, knapsack(i+1, w));
    };

    int ans = knapsack(0, p);
    debug(ans);

    cout << ans << endl;
}