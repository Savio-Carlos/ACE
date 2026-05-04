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

    int mid1, mid2;


    for (int i = 1; i < n; i++){
        if (a[i] + a[i-1] == x){
            pos = false;
            mid1 = a[i-1], mid2 = a[i];
            break;
        } 
    }
    if (pos){
        for (auto u : a) cout << u << " ";
        return 0;
    }
    vector<int> ans;
    if (mid1 == mid2){
        int cnt = mp[mid1];

        for (auto u : a){
            if (u == mid1) continue;
            if (cnt){
                ans.push_back(mid1);
                cnt--;
            } 
            ans.push_back(u);
        }
    }
    else {
        if (a[0] != mid1){
            int cnt = mp[mid2];
            while(cnt--){
                ans.push_back(mid2);
            }
            for (auto u : a){
                if (u == mid2) continue;
                ans.push_back(u);
            }
        }
        else{
            for (auto u : a){
                if (u == mid2) continue;
                ans.push_back(u);
            }
            int cnt = mp[mid2];
            while(cnt--){
                ans.push_back(mid2);
            }
        }
    }


    bool pos2 = true;
    for (int i = 1; i < n; i++){
        if (ans[i] + ans[i-1] == x) pos2 = false;
    }
    if (!pos2){
        cout << "*" << endl;
        return 0;
    }
    for (auto u : ans) cout << u << " ";
    
    
}