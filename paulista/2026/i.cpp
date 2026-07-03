#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)




bool valid(string &s){
    return s[0] == '1' && s[1] != '0' && s[2] == '9';
}

vector<string> p;

string s;


vector<string> todos;
void backtrack(string curr = {}, int pos = 0){

    if(curr.size() >= 3){
        if(!valid(curr)) return;
    }

    if(curr.size() >= 11){
        todos.push_back(curr);
        return;
    }

    if(curr.size() + s.size() - pos < 11){
        backtrack(curr + "1", pos);
        backtrack(curr + "9", pos);
    }
    if(pos < s.size()) backtrack(curr + s[pos], pos + 1);
}

signed main(){
    fastio;

    cin >> s;

    if(s.size() > 11) {
        cout << 0 << endl;
        return 0;
    }

    backtrack();

    sort(all(todos));
    todos.erase(unique(all(todos)), todos.end());

    cout << todos.size() << endl;
    for(auto &t:todos) cout << t << endl;
}