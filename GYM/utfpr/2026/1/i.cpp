#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    int sum = 0;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum&1){
        cout << "Nao\n";
        return 0;
    }

    vector<int> dp(sum + 5, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = dp.size() - 1; j >= 0; j--){
            if(j - arr[i] >= 0 && dp[j - arr[i]] != -1){
                dp[j] = 1;
            }
        }
    }

    // for(int i = 0; i < dp.size(); i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;


    if(dp[sum/2] != -1) cout << "Sim" << endl;
    else cout << "Nao" << endl;
}