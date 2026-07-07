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
    
    vector<int> l, r, m;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if (v * 2 < x) l.push_back(v);
        else if (v * 2 > x) r.push_back(v);
        else m.push_back(v);
    }
    
    if (m.size() > l.size() + r.size() + 1) {
        cout << "*" << endl;
        return 0;
    }

    
    sort(all(l));
    sort(all(r));
    
    vector<int> b;
    b.reserve(l.size() + r.size());
    for (int v : l) b.push_back(v);
    for (int v : r) b.push_back(v);
    
    bool req = false;
    int pos = l.size();
    
    if (!l.empty() && !r.empty() && l.back() + r.front() == x) {
        if (!m.empty()) {
            req = true;
        } 
        else {
            if (l.front() != l.back()) {
                swap(b[0], b[l.size() - 1]);
            } 
            else if (r.front() != r.back()) {
                swap(b[l.size()], b.back());
            } 
            else {
                cout << "*" << endl;
                return 0;
            }
        }
    }
    
    vector<bool> used(b.size() + 1, false);
    int cnt = 0;
    
    if (req) {
        used[pos] = true;
        cnt++;
    }
    
    for (int i = 0; i <= b.size() && cnt < m.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            cnt++;
        }
    }
    
    vector<int> ans;
    int idx = 0;
    
    for (int i = 0; i <= b.size(); ++i) {
        if (used[i]) {
            ans.push_back(m[idx++]);
        }
        if (i < b.size()) {
            ans.push_back(b[i]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
}