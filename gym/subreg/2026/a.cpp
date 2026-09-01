#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> c, k;
    for(int i = 0; i < n; i++){
        int ci, ki; cin >> ci >> ki;
        c.push_back(ci);
        k.push_back(ki);
    }

    vector<int> prefc(n+1, 0), prefv(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefc[i] = prefc[i-1] + c[i-1];
        prefv[i] = prefv[i-1] + k[i-1];
    }

    // for(int i = 1; i <= n; i++){
    //     cout << prefc[i] << " ";
    // }
    // cout << endl;

    // for(int i = 1; i <= n; i++){
    //     cout << prefv[i] << " ";
    // }
    // cout << endl;

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int amnt = prefc[x] - prefv[x];
        int amnt2 = prefc[x] + prefv[x];
        //cerr << amnt << " " << amnt2 << endl;
        if(amnt == 0) cout << "NEUTRO\n";
        else if(amnt > 0) cout << "COMPRA\n";
        else if(amnt < 0) cout <<"VENDA\n";
    }
}