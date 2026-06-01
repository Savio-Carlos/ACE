#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int INF = 1e7;

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> s(n);
        vector<int> pulos(n, INF);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }

        // plataforma 1 = 0

        int acc = 0;
        while(acc < n && s[acc] != '.'){
            pulos[acc] = 0;
            acc++;
        }

        int cnt = 0, minimo = INF;
        for(int i = 0; i < n; i++){

            if(s[i] == 'x') {
                cnt++;
                minimo = min(minimo, pulos[i]);
                pulos[i] = minimo;
            }

            if(i + 1 < n && s[i + 1] == '.'){
                for(int j = i+1; j <= i + cnt; j++){
                    // cout << i << " " << j << endl;
                    if(j < n) pulos[j] = min(pulos[j], pulos[i] + 1);
                }
                cnt = 0;
                minimo = INF;
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout << pulos[i] << " ";
        // } cout << endl;

        int ans = INF;
        acc = n - 1;
        while(acc >= 0 && s[acc] != '.'){
            ans = min(ans, pulos[acc]);
            acc--;
        }
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}