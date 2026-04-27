#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


signed main(){
    fastio;
    string t; cin >> t;
    if(t == "Encode"){
        int n; cin >> n;
        string s; cin >> s;
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            cout << s << endl;
        }else{
            for(int i = 0; i < n; i++){
                if(i <= idx) cout << 2;
                else cout << s[i];
            }
            cout << endl;
        }
    }else{
        int n; cin >> n;
        string s; cin >> s;
        int f = -1, brk = 0, second = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '2'){
                if(f == -1) f = i;
                if(brk && second == -1) second = i;
            }else if(f != -1){
                brk = 1;
            }
        }
        if(f == -1){
            cout << s << endl;
            return 0;
        }
        //cout << f << " " << second << endl;
        string st = "";
        int idx = 0;
        if(second != -1) idx = second;
        else idx = f;
        for(int i = 0; i < n; i++){
            st += s[(idx%n)];
            idx++;
        }

        st += '?';
        //cout << st << endl;
        for(int i = 0; i < n; i++){
            if(st[i] == '2'){
                if(st[i+1] == '2') cout << 0;
                else cout << 1;
            }else cout << st[i];
        }
        cout << endl;
    }   

}