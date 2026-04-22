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
    int n;
    cin >> n;
    map<int, vector<int>> ruas;
    map<int, int> somas;
    for (int i = 0; i < n; i++){
        int ri, ci;
        cin >> ri >> ci;
        ruas[ri].push_back(ci);
        somas[ri] += ci;
    }
    int ans = 0;
    for (auto [r, casas] : ruas){
        sort(all(casas));
        int m = casas.size();
        int med = casas[m/2];
        
        
        if (m%2 == 0){
            med = (med + casas[m/2-1]) / 2;
        }
        debug(med);
        debug(somas[r]);

        int cnt1 = 0, cnt2 = 0;
        int sum1 = 0, sum2 = 0;
        for (auto u : casas){
            if (u < med){
                cnt1++;
                sum1 += u;
            }
            else if (u > med) {
                cnt2++;
                sum2 += u;
            }
        }
        ans += (med * cnt1 - sum1) + (sum2 - cnt2 * med);
    }
    cout << ans << endl;
}