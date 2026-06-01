#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MOD = 1e9+7;

signed main(){
    fastio;
    int n; cin >> n;
    vector<pair<char, int>> v;
    while(n--){
        char op; cin >> op;
        if(op == '+' || op == '*'){
            int x; cin >> x;
            v.push_back({op, x});
        }else{
            int x; cin >> x;
            for(auto [op, k] : v){
                if(op == '+') x = (x+k)%MOD;
                else x = (x*k)%MOD;
            }
            cout << x << endl;
        }
    }


}