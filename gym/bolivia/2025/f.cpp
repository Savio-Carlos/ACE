#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)


int solve(vector<int> alt, vector<int> dis){

    int n = alt.size();

    vector<int> pref(n);
    for(int i = 1; i < n; i++){
        pref[i] += dis[i - 1] + pref[i - 1];
    }

    stack<pair<int,int>> stk;
    stk.push({alt[0], 0});
    int ans = 1;


    // while(!stk.empty() && ans < n){

    //     while(!stk.empty() && stk.top().first <= pref[ans] - stk.top().second){
    //         stk.pop();
    //     }

    //     if(stk.empty()) break;

    //     stk.push({alt[ans], pref[ans]});

    //     ans++;
    // }
    for(int i = 1; i < alt.size(); i++){
        while(!stk.empty() && stk.top().first <= pref[i] - stk.top().second){
            stk.pop();
        }

        if(stk.empty()) break;

        stk.push({alt[i], pref[i]});

        ans = max(ans, i + 1);
        
    }

    return ans;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> alt(n), dis(n - 1);
        for(int i = 0; i < n; i++){
            cin >> alt[i];
        }
        for(int j = 0; j < n - 1; j++){
            cin >> dis[j];
        }

        int ans = solve(alt, dis);

        reverse(all(alt));

        reverse(all(dis));

        ans = max(ans, solve(alt, dis));

        // cout << ans << endl;

        if(ans == n) cout << "habibi" << endl;
        else cout << "which" << endl;
    }
}