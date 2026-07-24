#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cerr << #x << ": " << x << endl;
int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> bulbs(m+1);
    vector<vector<int>> switches(n);
    int l;
    cin >> l;
    for (int i = 0; i < l; i++){
        int x;
        cin >> x;
        bulbs[x] = 1;
    }
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            switches[i].push_back(x);
        }
    }
    int on = l;
    for (int i = 0; i < 2*n; i++){
        int s = i%n;
        for (auto x : switches[s]){
            if (bulbs[x])on--;
            else on++;
            bulbs[x] ^= 1;    
        }
        if (on == 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}