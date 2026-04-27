#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++){
        int x;
         cin >> x;
         st.insert(x);
    }   
    cout << n - st.size() << endl;
}