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
    sort(all(a));
    bool pos = true;
    int mid = 0;
    for (int i = 1; i < n; i++){
        if (a[i] + a[i-1] == x){
            mid = a[i];
            pos = false;
            break;
        } 
    }
    if (pos){
        for (auto u : a) cout << u << " ";
        return 0;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (a[i] == mid) continue;
        ans.push_back(a[i]);
    }
    if (mid + mid != x){
        int cnt = mp[mid];
        vector<int> ans2;
        while(cnt--){
            ans.push_back(mid);
            ans2.push_back(mid);
        } 
        for (auto u : ans){
            if(u != mid) ans2.push_back(u);
        } 
        bool pos2 = true;
        for (int i = 1; i < n; i++){
            if (ans[i] + ans[i-1] == x) pos2 = false;
        }
        bool pos3 = true;
        for (int i = 1; i < n; i++){
            if (ans2[i] + ans2[i-1] == x) pos3 = false;
        }
        if (!pos2 && !pos3){
            cout << "*" << endl;
            return 0;
        }
        if (pos2)for (auto u : ans) cout << u << " ";
        else if (pos3)for (auto u : ans2) cout << u << " ";
        return 0;
    }
    vector<int> ans2;
    int cnt = mp[mid];
    for (int i = 0; i < ans.size(); i++){
        if (ans[i] + mid != x && cnt){
            ans2.push_back(mid);
            cnt--;
        } 
        ans2.push_back(ans[i]); 
    }
    while(cnt--) ans2.push_back(mid);
    
    bool pos2 = true;
    for (int i = 1; i < n; i++){
        if (ans2[i] + ans2[i-1] == x) pos2 = false;
    }
    if (!pos2){
        cout << "*" << endl;
        return 0;
    }
    for (auto u : ans2) cout << u << " ";
    
}