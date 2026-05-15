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
    int n; cin >> n;

    cout << "YES\n";
    if(n == 1){
        cout << 3 << " " << 2 << endl;
    }
    else if(__builtin_popcountll(n) == 1){
        cout << n+1LL << " " << 1LL << endl;
    }

    else if(n == 0){
        cout << 4 << " " << 4 << endl;
        return 0;
    }else{
        int low = (n & (-n));
        int a = low;
        int b = n^low;
        cout << a << " " << b << endl;
    }

    
}