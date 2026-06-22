#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAXN = 300;
int grid[MAXN][MAXN];
int custo[MAXN];
int n, m;

map<pair<int, string>, int> dp;

int pd(int idx, string visitados){
    if(idx == n) return 0;
    if(dp.find({idx, visitados}) != dp.end()) return dp[{idx, visitados}];

    string nmask = visitados;
    int res = LLONG_MAX;
    for(int j = 0; j < m; j++){
        int cost = 0;
        if(visitados[j] == '0') cost = custo[j];
        nmask[j] = '1';
        res = min(res, pd(idx+1, nmask) + cost + grid[idx][j]);
        nmask[j] = visitados[j];
    }
    return dp[{idx, visitados}] = res;
}

void solve(){
    cin >> n >> m;
    dp.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> grid[i][j];
    }
    string s = "";
    for(int i = 0; i < m; i++){
        cin >> custo[i];
        s += "0";
    }

    cout << pd(0, s) << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--)solve();
}