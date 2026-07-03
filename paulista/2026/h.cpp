#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    int cur = 300;
    int delay = 0;
    int sum = 0;
    bool f = false, s = false;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        if (cur + x > 420 && !f){
            int rem = (cur+x) - 420;
            cur = 600 + rem;
            delay += 180;
            f = true;
        }
        else if (cur + x > 1020 && !s){
            int rem = (cur+x) - 1020;
            cur = 1200 + rem;
            delay += 180;
            s = true;
        }
        else cur += x;
    }
    cout << sum + delay << endl;
}