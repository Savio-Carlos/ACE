#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

bool variable(string s){
    if(s.size() != 1) return false;
    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) return true;
    return false;
}

#define P pair<vector<string>, map<string, int>>

P pattern(vector<string> str){
    map<string, int> mp;
    vector<string> v;
    for(int i = 0; i < (int)str.size(); i++){
        if(variable(str[i])){
            if(mp.find(str[i]) == mp.end()) v.push_back("0");
            else {
                string val = to_string(i - mp[str[i]]);
                v.push_back(val);
            }
            mp[str[i]] = i;
        } else v.push_back(str[i]);
    }
    P x;
    x.first = v;
    x.second = mp;
    return x;
}

void solve(){
    fastio;
    int n; cin >> n;
    vector<string> ref;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ref.push_back(s);
    }

    vector<vector<string>> pfx;
    pfx.reserve(n);
    for (int i = 0; i < n; ++i){
        vector<string> cur;
        map<string,int> last;
        cur.reserve(n - i);
        for (int j = i; j < n; ++j){
            string s = ref[j];
            if (variable(s)){
                string o = s;
                if (last.find(s) != last.end()) s = to_string(j - last[s]);
                else s = "0";
                last[o] = j;
            }
            cur.push_back(s);
        }
        pfx.push_back(move(cur));
    }
    sort(pfx.begin(), pfx.end());

    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        vector<string> strings;
        strings.reserve(m);
        map<string,int> lastq;
        for(int i = 0; i < m; i++){
            string s; cin >> s;
            if (variable(s)){
                string o = s;
                if (lastq.find(s) != lastq.end()) s = to_string(i - lastq[s]);
                else s = "0";
                lastq[o] = i;
            }
            strings.push_back(s);
        }

        auto it = lower_bound(pfx.begin(), pfx.end(), strings);
        if (it == pfx.end()){
            cout << "no\n";
            continue;
        }

        vector<string> res = *it;
        bool match = true;
        if ((int)res.size() < m) match = false;
        else {
            for (int i = 0; i < m; ++i){
                if (res[i] != strings[i]) { match = false; break; }
            }
        }
        cout << (match ? "yes\n" : "no\n");
    }
}

signed main(){
    int t = 1;
    while(t--) solve();
    return 0;
}
