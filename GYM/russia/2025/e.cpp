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
    string s;
    cin >> s;
    bool era_sinal = false;
    stack<int> st;
    st.push(1);
    int n = s.size();
    for (int i = 0; i < n; i++){
        // cout << "i: " <<i  << " st top: " << st.top() << endl;
        if (s[i] >= '0' && s[i] <= '9') era_sinal = false;

        if (s[i] == '-'){
            if (st.top() == -1){
                s[i] = '+';
            }
            era_sinal = true;
        }
        if (s[i] == '+'){
            if (st.top() == 1){
                s[i] = '-';
            }
            era_sinal = true;
        }

        if (s[i] == '('){
            int ctx = (era_sinal ? -1 : st.top());
            st.push(ctx);
            era_sinal = false;
        }
        
        if (s[i] == ')'){
            st.pop();
            era_sinal = false;
        }
    }
    cout << s << endl;
}