#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n, q; 
    cin >> n >> q;
    vector<int> a(n+1);
    vector<int> pfxPot(n+1), pfxOdd(n+1), pfxum(n+1);

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1) pfxum[i]++;
        else if (a[i]&1) pfxOdd[i] += a[i];
        else if (__popcount(a[i]) == 1) pfxPot[i] += a[i];
    }

    for (int i = 1; i <= n; i++){
        pfxPot[i] += pfxPot[i-1];
        pfxum[i] += pfxum[i-1];
        pfxOdd[i] += pfxOdd[i-1];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int agu = pfxPot[r] - pfxPot[l-1];
        int bri = pfxOdd[r] - pfxOdd[l-1];
        
        int uns = pfxum[r] - pfxum[l-1];
        
        // cout << agu << " " << bri << " " << uns << endl;
        agu += (uns+1)/2;
        bri += uns/2;
        if (agu > bri) cout << "A" << endl;
        else if (bri > agu) cout << "B" << endl;
        else cout << "E" << endl;
    }
}