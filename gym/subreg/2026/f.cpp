#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

const int MAX = 1e7 + 3;

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> res(MAX, -1);

    res[1] = 2;

    int pos = 1, val = 2;
    while(pos < MAX){
        // cout << pos << " " << val << endl;
        res[pos] = val;
        swap(pos, val);
        val *= 3;
    }

    //   for(int i = 0; i < 20; i++){
    //     cout << res[i] << " ";
    // }
    // cout << endl;


    for(int i = 1; i < MAX; i++){
        if(res[i] == -1) {
            res[i] = res[i-1] + 1;
            pos = i;
            val = res[i];
            while(pos < MAX){
                // cout << pos << " " << val << endl;
                res[pos] = val;
                swap(pos, val);
                val *= 3;
            }
        }
    }


    // for(int i = 0; i < 100; i++){
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    cout << res[n] << endl;
}