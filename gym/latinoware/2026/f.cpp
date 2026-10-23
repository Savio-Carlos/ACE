#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    array<int, 3> mx{};
    array<int, 3> ans{};

    for (auto &u : mx) cin >> u;

    auto ask = [&]() -> int{
        cout << "? " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        int ret;
        cin >> ret;
        if (ret == 2) exit(0);
        return ret;
    };

    for (int i = 0; i < 3; i++){
        int l = 0, r = mx[i] - 1;
        
        while (l < r){
            int mid = l + ((r-l) / 2);
            ans[i] = l;
            ask();
            ans[i] = r;
            if (ask() == 1) l = mid + 1;
            else r = mid;
        }
        ans[i] = l;
    }

    ask();
}