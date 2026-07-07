#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


vector<string> formatar(vector<string> v) {
    for(int i = 0; i < v.size(); i++){
        while(v[i].size() != 4){
            v[i] = "0" + v[i];
        }
    }
    return v;
}

vector<string> separar(string s){
    string aux;
    vector<string> ret;
    for(int i = 0; i < s.size(); i++){

        if(s[i] == ':'){

            if(!aux.empty()){
                ret.push_back(aux);
            }
            
            aux = {};
            continue;
        }

        aux += tolower(s[i]);
    }
    if(!aux.empty()) ret.push_back(aux);
    return ret;
}

signed main(){
    fastio;
    string s;
    cin >> s;
    int i = 0, n = s.size();

    string first, second;

    first = s[0];
    second = s[n-1];

    for(int i = 1; i < n; i++){
        if(s[i - 1] == ':' && s[i - 1] == s[i]) break;
        first += s[i];
    }

    for(int i = n-2; i >= 0; i--){
        if(s[i + 1] == ':' && s[i + 1] == s[i]) break;
        second += s[i];
    }

    reverse(second.begin(), second.end());



    // cout << first << endl << second << endl;


    // for(auto r:separar(first)) cout << r << " ";
    // cout << endl;

    // for(auto r:separar(second)) cout << r << " ";
    // cout << endl;

    // for(auto r:formatar(separar(first))) cout << r << " ";
    // cout << endl;

    // for(auto r:formatar(separar(second))) cout << r << " ";

    // cout << endl;

    auto esq = formatar(separar(first));
    auto dir = formatar(separar(second));

    vector<string> ans;

    if(esq.size() == 8) ans = esq;
    else {
        for(auto e:esq) ans.push_back(e);
        for(int i = 0; i < 8 - (esq.size() + dir.size()); i++){
            ans.push_back("0000");
        }
        for(auto d:dir) ans.push_back(d);
    }

    for(int i = 0; i < 8; i++){
        cout << ans[i];
        if(i < 7) cout << ":";
    }
    cout << endl;

    

}