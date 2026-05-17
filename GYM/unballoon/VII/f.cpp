#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
const int MOD = 998244353;
//a eduarda e bobona
signed main() {
    fastio;
    int n; 
    cin >> n;
    vector<int> l(n+1), pos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        pos[l[i]] = i;
    }

    vector<int> pot2(n+1);
    pot2[0] = 1;
    for (int i = 1; i <= n; i++) pot2[i] = pot2[i-1] * 2 % MOD;

    vector<int> visited(n+1, 0);
    vector<int> path;
    path.reserve(n);

    int ans = 0;
    for (int k = 0; k < n; k++) {
        fill(all(visited), 0);
        int ciclos = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            int cur = i;
            path.clear();

            while (cur >= 1 && cur <= n && visited[cur] == 0) {
                visited[cur] = 1;
                path.push_back(cur);
                cur = pos[cur] - k;
            }

            if (cur >= 1 && cur <= n && visited[cur] == 1) ciclos++;
            for (int u : path) visited[u] = 2;
        }
        ans = (ans + pot2[ciclos] - 1 + MOD) % MOD;
    }

    cout << ans << endl;
}