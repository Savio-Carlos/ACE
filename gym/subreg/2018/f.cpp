#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<vector<tuple<int,int,int>>> shows(86405);
    int tot = (1 << n) - 1;
    int mx = 0;
    vector<vector<int>> dp(86500, vector<int>(tot+1,-1));

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x, y, s;
            cin >> x >> y >> s;
            shows[y].push_back({x,s,i});
            dp[y][0] = 0;
            mx = max(mx, y);
        } 
    }

    for (int i = mx; i >= 0; i--){
        dp[i][0] = 0;

        for (int mask = 0; mask <= tot; mask++){
            dp[i][mask] = max(dp[i][mask],dp[i+1][mask]);
        }

        for (auto [start, score, b] : shows[i]){
            for (int mask = 0; mask <= tot; mask++){
                if (dp[i][mask] == -1) continue;
                int novamask = mask|(1<<b);
                dp[start][mask] = max(dp[start][mask], dp[i][mask]);
                dp[start][novamask] = max(dp[start][novamask], dp[i][mask] + score);
            }
        }
    }
    cout << dp[0][tot] << endl;
}