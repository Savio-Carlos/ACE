#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    fastio;
    int n; cin >> n;
    int sa = 0, sb = 0, m = 0;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        sa += x;
        sb += y;
        m = max(m, x + y);
    }

    cout << max(abs(sa-sb), 2*m - (sa + sb)) << endl;
}