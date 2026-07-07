#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto&u : a)cin>>u;
    vector<int> before, after(n);
    int cur = 0;
    for (int i = 0; i < n; i++){
        before.push_back(cur);
        if (a[i]==1)cur = 0;
        else cur++;
    }
    cur = 0;
    for (int i = n-1; i >=0; i--){
        after[i] = cur;
        if (a[i]==1)cur = 0;
        else cur++;
    }
    // vdebug(before);
    // vdebug(after);
    int ans = 0;
    int sum_odd = 0;
    int sum_even = 0;
    int qtd = 0;

    for (int i = 0; i < n; i++){
        if (a[i]==0) continue;
        qtd++;
        if (qtd&1){
            sum_odd += before[i] + 1;
            ans += sum_odd * (after[i] + 1); 
        }
        else {
            sum_even += before[i] + 1;
            ans += sum_even * (after[i] + 1); 
        }
        // debug(ans);
    }
    cout << ans << endl;
}