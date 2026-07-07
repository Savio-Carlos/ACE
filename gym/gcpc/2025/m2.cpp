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
    int n, d; 
    cin >> n >> d;
    map<int,vector<int>> mp;
    int minmex = 0;
    set<int> temp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        temp.insert(x);
        while(temp.count(minmex)) minmex++;
        mp[x].push_back(i);
    }

    auto check = [&] (int v) -> bool{
        auto a = mp[v];
        debug(v, a, d);
        int l, r, free = 0;
        priority_queue<int, vector<int>, greater<int>> pq(all(a));

        while(!pq.empty()){
            if (pq.top() < free) return false;

            l = pq.top();
            r = l + d - 1;
            pq.pop();

            int last = l;
            while(!pq.empty() && pq.top() <= r){
                last = pq.top();
                pq.pop();
            }
            debug(l, r, last);
            int diff_start = l - free;
            int diff_end = r - last;

            if (diff_start < diff_end){
                l = free;
                r = l + d - 1;
            }
            else{
                r = last;
                l = r - d + 1;
            }
            free = min<int>(n, r + d + 1);
            debug(l, r, free);
        }
        return true;
    };

    int ans = minmex;
    for(int v = 0; v < minmex; v++) {
        if (check(v)) {
            ans = v;
            break;
        }
    }
    cout << ans << endl;
}