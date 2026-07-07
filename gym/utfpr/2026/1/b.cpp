#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    cout << fixed << setprecision(20);
    if (r < l){
        int todos = n - l + r + 1;
        if (k <= r or k >= l) todos--;
        cout << (100.0 / ((double) n - 1) * (double)todos) / 100.0 << endl;    
    }
    else{
        int todos = r-l+1;
        if(k >= l && k <= r)todos--;
        cout << (100.0 / ((double) n - 1) * (double)todos) / 100.0 << endl;    
    }
}