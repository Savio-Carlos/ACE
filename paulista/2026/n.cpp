#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;


signed main(){
    fastio;
    int n;
    cin >> n;   
    int sum = 0;
    vector<int> a(n+2);
    for (auto &u : a){
        cin >> u;
        sum += u;
    } 
    sort(all(a));
    int s = a.back();
    sum -= s;
    multiset<int> ans;
    int m = sum - (s*(n-1));
    for (auto u : a){
        ans.insert(s - u);
    }
    ans.erase(ans.find(0));
    ans.erase(ans.find(s-m));
    cout << s << " " << m << endl;
    for (auto u : ans) cout << u << " ";
    cout << endl;
}