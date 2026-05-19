#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define ld long double

signed main(){
    fastio;
    int h1, m1, h2, m2;
    char trash;
    cin >> h1 >> trash >> m1;
    cin >> h2 >> trash >> m2;

    int tot1 = h1*60+m1;
    int tot2 = h2*60+m2;

    int hf = (tot1 - tot2) / 60;    
    int mf = (tot1 - tot2) % 60;
    if(hf < 10) cout << 0;
    cout << hf << ":" ;
    if (mf < 10) cout << 0;
    cout << mf;
    cout << endl;
}