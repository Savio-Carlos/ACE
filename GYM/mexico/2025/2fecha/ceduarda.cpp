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

const int MOD = 998244353;
const int MAXN = 1e5+7;

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> dp(n+1, 0), sum(MAXN, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        dp[i] = (dp[i] + dp[i-1])%MOD;
        dp[i] = (dp[i] + sum[x])%MOD;
        sum[x] += dp[i-1];
    }
    cout << dp[n] << endl;
}