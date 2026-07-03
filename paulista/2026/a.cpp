#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> club(n), group(q);
    for(int i = 0; i < n; i++){
        cin >> club[i].first >> club[i].second;
    }
    for (auto &[u,v] : group) cin >> u >> v;

    vector<int> proximo(n+1);
    proximo[n-1] = -2;
    for (int i = n-2; i >= 0; i--){
        if (club[i].second == club[i+1].second){
            proximo[i] = proximo[i+1];
        }
        else proximo[i] = i+1;
    }
    vdebug(proximo);
    for (auto [valor, tipo] : group){
        int l = 0, r = n-1;
        int ans = -1;
        while (l <= r){
            int mid = (l+r)/2;
            if (club[mid].first > valor){
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        if (ans == -1) cout << -1 << endl;
        else if (ans != -1 && club[ans].second == tipo) cout << proximo[ans]+1 << endl;
        else cout << ans+1 << endl;
    }

}