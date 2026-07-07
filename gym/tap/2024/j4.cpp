#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, x;
    cin >> n >> x;
    map<int,int> mp;
    vector<int> a(n), r;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> ans;
    sort(all(a));
    
    auto add = [&] (int u) -> void{
        ans.push_back(u);
        mp[u]--;
        if (!mp[u]) mp.erase(u);
    };
    
    int last = a[n-1];
    add(a[n-1]);
    for (int i = 1; i < n; i++){

        bool found = false;
        for (auto [u, cnt] : mp){
            if (u + last != x || last == -1){
                add(u);
                last = u;
                found = true;
                break;
            }
        }
        if (!found){
            cout << "*" << endl;
            return 0;
        }
    }
    for (auto u : ans) cout << u << " ";
}