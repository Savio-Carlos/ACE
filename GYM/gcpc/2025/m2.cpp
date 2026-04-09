#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

bool check(int v, const vector<int>& a, int d) {
    int avail = 0;
    int idx = 0;
    while(idx < a.size()) {
        int target = a[idx];
        if (avail > target) return false;
        
        int s = max(avail, target - d + 1);
        while (true) {
            if (s > target) return false;
            
            auto it = upper_bound(a.begin() + idx, a.end(), s + 2 * d - 1);
            if (it != a.begin() + idx) {
                auto prev_it = prev(it);
                if (*prev_it >= s + d) {
                    s = *prev_it - d + 1;
                    continue;
                }
            }
            break;
        }
        
        avail = s + 2 * d;
        idx = lower_bound(a.begin() + idx, a.end(), avail) - a.begin();
    }
    return true;
}

signed main(){
    fastio;
    int n, d; 
    cin >> n >> d;
    map<int,vector<int>> mp;
    int minmex = 0;
    set<int> temp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        temp.insert(x);
        while(temp.count(minmex)) minmex++;
        mp[x].push_back(i);
    }
    int ans = minmex;
    for(int v = 0; v < minmex; v++) {
        if (check(v, mp[v], d)) {
            ans = v;
            break;
        }
    }
    cout << ans << endl;
}