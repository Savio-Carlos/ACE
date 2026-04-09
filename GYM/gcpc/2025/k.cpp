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
    int n, a, b; cin >> n >> a >> b;
    if(a == 1 && b == 1){
        if(n == 1){
            cout << "yes\n";
            cout << 1 << endl;
        }else cout << "no\n";
        return 0;
    }

    if(n+1 >= a + b){
        cout << "yes\n";
        bool trocado = false;
        if(a > b) {
            swap(a, b);
            trocado = true;
        }

        deque<int> dq;
        for(int i = 1;i <= n; i++) dq.push_back(i);
        vector<int> arr, arr2;

        a--;
        while(a--){
            arr.push_back(dq.front());
            dq.pop_front();
        }

        
        arr.push_back(dq.back());
        dq.pop_back();
        
        
        b--;
        while(b--){
            arr2.push_back(dq.back());
            dq.pop_back();
        }

        
        
        for(auto u : dq){
            arr.push_back(u);
        }


        // for(auto u : arr) cout << u << " ";
        // for(auto u : arr2) cout << u << " ";
        for(auto u : arr2) arr.push_back(u);
        if (trocado) reverse(arr.begin(), arr.end());
        for(auto u : arr) cout << u << " ";
        cout << endl;

    }else cout << "no\n";
}

