#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int ans = 0;

vector<int> solve(vector<int> v){
    int n = v.size();
    vector<int> res;
    for(int i = 0; i < n; i += 2){
        if(i + 1 < n){
            ans = max(ans,abs(v[i] - v[i+1]));
            res.push_back(max(v[i], v[i+1]));
        } else {
            res.push_back(v[i]);
        }
    }

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // } cout << endl;
    return res;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &w:v) cin >> w;
    while(v.size() > 1){
        v = solve(v);
    }
    cout << ans << endl;
}