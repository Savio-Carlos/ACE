#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

//StringStream

vector<string> split_sentence(string s){
    stringstream ss(s);

    string word;

    vector<string> v;

    while(getline(ss, word, ' ')){
        v.push_back(word);
    }
    return v; 
}

void solve(vector<string> &v){
    for(int i = 0; i < v.size(); i++){

        bool numero = true;
        for(int j = 0; j < v[i].size(); j++){
            if(!(v[i][j] - '0' >= 0 && v[i][j] - '0' <= 9)){
                numero = false;
            }
        }

        if(numero == false || v[i].size() < 4) continue;

        int j = v[i].size() - 1;
        while(i >= 0 && v[i][j] == '0'){
            j--;
        }

        int zeros = v[i].size() - j - 1;

        if(zeros < 4) continue;

        if (j == 0){

            if(v[i][j] == '1') v[i] = "10^{" + to_string(zeros) + "}";
            else {
                string aux = {};
                aux += v[i][j];
                v[i] = aux + "\\cdot10^{" + to_string(zeros) + "}";
            }

        } else {

            string aux = {};

            aux += v[i][0];
            aux += ".";

            for(int k = 1; k < v[i].size() - zeros; k++){
                aux += v[i][k];
            }

            v[i] = aux + "\\cdot10^{" + to_string(v[i].size() - 1) + "}";

        }
    }
}

signed main(){
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        

        // cout << s << endl;

        vector<string> aux = split_sentence(s);

        solve(aux);

        for(int i = 0; i < aux.size(); i++){
            cout << aux[i];
            if(i != aux.size() -1)cout << " ";
        } cout << endl;

    }

    
}