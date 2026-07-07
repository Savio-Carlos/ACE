#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    //fastio;
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<int> visited(n, 0);
    string t = s;
    //cout << t << endl;
    for(int i = 0; i < k; i++){
        if(!visited[i]){
            visited[i] = 1;
            int idx = i;
            vector<char> v;
            while(idx < n){
                visited[idx] = 1;
                v.push_back(s[idx]);
                idx+=k;
            }
            idx = i;
            sort(v.begin(), v.end());
            for(auto a : v){
                //cout << a << " " << idx << endl;
                t[idx] = a;
                idx += k;
            }
            //cout << endl;
        }
    }
    cout << t << endl;
}