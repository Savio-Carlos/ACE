#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    fastio;
    int n, d; cin >> n >> d;
    map<int, int> lst, nxt;
    vector<int> mex(n+1, 1);
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        
        if(lst[x] >= i) continue;    
        else{
            //posso colocar um escudo aq
            if(nxt[x] < i){
                lst[x] = i+d-1;
                nxt[x] = i+d+d;
            }else{
                cout << x << " " << i << endl;
                mex[x] = 0;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        if(mex[i]){
            cout << i << endl;
            return 0;
        }
    }

}