#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    fastio;
    int n;
    string instruction, s;
    cin >> instruction >> n >> s;
   
    if (instruction == "Encode"){
        string r = s;
        if(s.find("1") == string::npos){
            cout << s << endl;
            return 0;
        }
        int i = 0;
        while(i < n && s[i] == '0') r[i++] = '2';
        if (i < n && r[i] == '1') r[i] = '2';
        cout << r << endl;
    }
    else{
        int i = 0; 
        string r = s;   
        
        while(i < n && s[i] != '2') i++;
        while(i < n && s[i] == '2'){
            r[i] = '0';
            i++;
        }
        if (i-1 < n) r[i-1] = '1';
        cout << r << endl;
    }

}

