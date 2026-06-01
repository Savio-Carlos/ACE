#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)


signed main(){
    fastio;
    int n, g;
    cin >> n >> g;
    int size = n/g;
    int resto = n%g;
    cout << g*(size+1) + resto << endl;
}