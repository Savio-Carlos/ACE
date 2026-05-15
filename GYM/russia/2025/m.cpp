#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    // fastio;
    int n, k;
    cin >> n >> k;
    set<int> avail;
    for (int i = 0; i < n; i++) avail.insert(i);

    while(k--){
        int hi;
        cin >> hi;

        // for (auto tt : avail){
        //     cout << tt << " ";
        // }   cout << endl;


        if (avail.find(hi) != avail.end()){
            cout << hi << endl;
            avail.erase(hi);
            // cout << "hi: " << hi << endl;
        }
        else{
            auto it = avail.lower_bound(hi);
            if (it == avail.end()) it--;
            int p1 = *it;
            if (it != avail.begin()){
                auto it2 = it;
                it2--;
                int p2 = *it2;
                if (abs(hi-p2) <= abs(hi-p1)){
                    cout << p2 << endl;
                    avail.erase(it2);
                    // cout << "p2: " << p2 << endl;
                }
                else {
                    // cout << "p1: " << p1 << endl;
                    cout << p1 << endl;
                    avail.erase(it);
                }
            }
            else {
                cout << p1 << endl;
                avail.erase(it);
            }
        }

    }
}