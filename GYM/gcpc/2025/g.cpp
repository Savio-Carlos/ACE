#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#include <random>
#include <chrono>

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(33, 126);//valores min e max
uniform_int_distribution<int> siz(8, 12);
uniform_int_distribution<int> mais(65, 90);
uniform_int_distribution<int> minu(97, 122);
uniform_int_distribution<int> num(48, 57);
uniform_int_distribution<int> spe(33, 44);
uniform_int_distribution<int> spe2(58, 64);



signed main(){
    fastio;
    int n;
    cin >> n;
    while(n--){
        int sz = siz(rng);
        for (int i = 1; i <= sz; i++){
            char x = dist(rng);

            if(i%4 == 0) x = mais(rng);
            else if(i%3 == 0) x = minu(rng);
            else if (i%5 == 0) x = num(rng);
            else if (i%6 == 0) x = spe(rng);
            else if (i%7 == 0) x = spe2(rng);
            cout << x;
        }
        cout << endl;
    }


}