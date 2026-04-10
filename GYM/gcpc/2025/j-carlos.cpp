#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
// #define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n;
    string instruction, s;
    cin >> instruction >> n >> s;
    
    auto checkzero = [&] () -> bool{
        int cnt = 0;
        for (auto c : s) if(c == '0') cnt++;
        return cnt == n;
    };

    if(checkzero()){
        cout << s << endl;
        return 0;
    }


    if (instruction == "Encode"){
        string r = s;
        int i = 0;
        while(i < n && s[i] == '0') r[i++] = '2';
        if (i < n && r[i] == '1') r[i] = '2';
        cout << r << endl;
    }
    else{
        if (count(all(s), '2') == n){
            for (int i = 0; i < n-1; i++) cout << '0';
            cout << '1' << endl;
            return 0;
        }
        string r = s;

        int p = 0;
        for (int i = 0; i < n; i++) if(s[i] != '2'){ 
            p = i; 
            break; 
        }
        int bs = p;
        for (int j = 1; j <= n; j++) if(s[(p+j)%n] == '2'){
            bs = (p+j)%n; 
            break; 
        }
        
        int st = bs;
        for (int j = 1; j < n; j++){
            int pos = (bs+j)%n;
            if(s[pos] == '2') st = pos;
            else break;
        }
        r[st] = '1';
        for(auto &c : r) if(c == '2') c = '0';
        for (int i = 0; i < n; i++){
            cout << r[(i+bs)%n];
        }
        cout << endl;
    }
}

