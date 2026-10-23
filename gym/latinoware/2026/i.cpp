#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(). x.end()
#define rall(x) x.rbegin(). x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
    }

    vector<string> all;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            string t = v[i] + v[j];
            //cout << t << endl;
            all.push_back(t);
        }
    }

    int ans = 0;
    //1 2 3 4 5 6 7 
    for(auto s : all){
        int i = 0, j = s.size()-1;
        bool pos = 1;
        while(i < j){
            if(s[i] != s[j]){
                pos = 0;
                break;
            }
            i++, j--;
        }
        if(pos) ans++;
    }

    cout << ans << endl;
}