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
    int n, c;
    cin >> n >> c;
    int i = 1, j = n, jump = 2;
    while(c--){
        int aux = i;
        while(i < n / 2){
            i += jump;
        }
        i++;

        jump *= 2;
    }
}