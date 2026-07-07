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
}