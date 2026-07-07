#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    fastio;
    int n; cin >> n;
    map<string, pair<int, int>> mp;
    mp["single"] = {760, 1};
    mp["double"] = {1900, 2};
    mp["triple"] = {5700, 3};
    mp["tetris"] = {22800, 4};
    int level = 18, ans = 0, rows = 0, nxt = 130;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        auto [amnt, inc] = mp[s];
        ans += mp[s].first;
        rows += inc;
        if(rows >= nxt){
            nxt += 10;
            mp["single"].first += 40;
            mp["double"].first += 100;
            mp["triple"].first += 300;
            mp["tetris"].first += 1200;
            level++;
        }
    }

    cout << ans << " " << level << endl;
}