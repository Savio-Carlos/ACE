#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;
#define debugp(x) cerr << #x << ": " << x.first << " " << x.second << endl

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> a(2*n);
    for (auto &[u,v] : a) cin >> u >> v;

    sort(all(a), [](auto a, auto b) {
        return (a.first + a.second) > (b.first + b.second); 
    });
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < n; i++){
        // debugp(a[i]);
        ans1 += a[i].first;
    }
    for (int i = n; i < 2*n; i++){
        // debugp(a[i]);
        ans2 += a[i].second;
    }
    cout <<ans1 - ans2 << endl;
}