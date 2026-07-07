#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAXN = 1e6+7;
vector<int> graph[MAXN];
int val[MAXN], resposta[MAXN];

void dfs(int v, int p, vector<int> &ans){
    resposta[v] = (int)ans.size();
    // debug(v);
    // vdebug(ans);
    for(auto u : graph[v]){
        if(u == p) continue;
        int it = lower_bound(ans.begin(), ans.end(), val[u]) - ans.begin();
        if(it == ans.size()){
            ans.push_back(val[u]);
            dfs(u, v, ans);
            ans.pop_back();
        }else{
            int prev = ans[it];
            ans[it] = val[u];
            dfs(u, v, ans);
            ans[it] = prev;
        }
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        val[i] = x;
    }
    vector<int> ans;
    ans.push_back(val[1]);
    dfs(1,-1, ans);
    for(int i = 2; i <= n; i++){
        cout << resposta[i] << " ";
    }
    cout << endl;
}