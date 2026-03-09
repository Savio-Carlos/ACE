#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

/*
o que eu preciso guardar?
priority_queue 
v1, posicao inicial, momento q foi removido
*/

void solve(){
    int n; cin >> n;
    vector<vector<int>> elim(n+2);
    int x; cin >> x;
    bool pos = true;
    if(x != 0){
        pos = false;
    }

    int m = (1<<n);
    for(int i = 2; i <= m; i++){
        cin >> x;
        elim[x].push_back(i);
    }

    if(!pos){
        cout << -1 << endl;
        return;
    }
    vector<int> res = {1};
    for(int i = n; i > 0; i--){
        vector<int> rem = res;
        sort(rem.begin(), rem.end());
        sort(elim[i].begin(), elim[i].end());
        vector<int> newrem;
        map<int, int> ordem;
        for(int j = 0; j < elim[i].size(); j++){
            if(rem[j] > elim[i][j]){
                cout << -1 << endl;
                return;
            }
            ordem[rem[j]] = elim[i][j];
        }
        for(auto u : res){
            newrem.push_back(u);
            newrem.push_back(ordem[u]);
        }
        res = newrem;
    }

    for(int i = 0; i < m; i++){
        cout << res[i] << " ";
    }
    cout << endl;

}

signed main(){
    //fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}