#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

int main(){
    fastio;
    int n;
    cin >> n;
    bool can_in_one = false;
    int xr = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (!x or !y or x == y){
            can_in_one = 1;
            continue;
        } 
        
        int up = (y >= 2 ? abs(y-2) + abs(x-1) : 0); 
        int left = (x >= 2 ? abs(x-2) + abs(y-1) : 0);
        if (x < y) left--;
        else up--; 
        
        xr ^= max(left, up);
        // cout << xr << " " << up << " " << left << endl;
    }   

    if (can_in_one or xr) cout << "Y" << endl;
    else cout << "N" << endl;
}