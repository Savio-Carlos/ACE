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

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

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

signed main(){
    winton;
    i   nt n;
    cin >> n;
    vector<string> grid(n);
    for (auto &u : grid) cin >> u;

    debug(grid);
    auto equal3 = [&] (string a, string b, string c, string d) -> bool {
        vector<string> strings = {a, b, c, d};
        unordered_map<string, int> cnt;

        for (const auto& s : strings) {
            cnt[s]++;
        }

        for (auto const& [str, count] : cnt) {
            if (count >= 3) return true;
        }
        return false;
    };

    auto check = [&] (int tamanho) -> bool {

        string ul = "";
        string ur = "";
        string bl = "";
        string br = "";

        //upper left e minha base
        for (int i = 0; i < tamanho; i++){
            for (int j = 0; j < tamanho; j++){
                ul += grid[i][j];
            }
        }

        //upper right comeca la na direita e vai coluna por coluna para a esquerda
        for (int j = n - 1; j >= n - tamanho; j--){
            for (int i = 0; i < tamanho; i++){
                ur += grid[i][j];
            }
        }
        
        //bottom right comeca no [n][n] e vai voltando percorrendo cada linha
        for (int i = n - 1; i >= n - tamanho; i--){
            for (int j = n - 1; j >= n - tamanho; j--){
                br += grid[i][j];
            }
        }
        
        //bottom left comeca no esquerda embaixo e vai subindo coluna por coluna
        for (int j = 0; j < tamanho; j++){
            for (int i = n - 1; i >= n - tamanho; i--){
                bl += grid[i][j];
            }
        }

        debug(ul);
        debug(ur);
        debug(bl);
        debug(br);

        return equal3(ul,ur,bl,br);

    };

    int l = 0, r = n/2;
    int ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        debug(mid);
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}