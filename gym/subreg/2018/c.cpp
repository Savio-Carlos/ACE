#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()


struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }

    void upd(int x, int v){
        for(x++; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};


signed main(){
    fastio;
    int x, y, h, v;
    cin >> x >> y >> h >> v;

    vector<pair<int,int>> horizontais(h), verticais(v);
    vector<int> todos_x, todos_y;

    for (auto &[y1,y2] : horizontais){
        cin >> y1 >> y2;
        todos_y.push_back(y1);
        todos_y.push_back(y2);
    }
    for (auto &[x1,x2] : verticais){
        cin >> x1 >> x2;
        todos_x.push_back(x1);
        todos_x.push_back(x2);
    }

    sort(all(todos_y));
    todos_y.erase(unique(all(todos_y)), todos_y.end());
    sort(all(todos_x));
    todos_x.erase(unique(all(todos_x)), todos_x.end());

    auto comp_y = [&](int yy) -> int{
        return (lower_bound(all(todos_y), yy) - todos_y.begin());
    };
    auto comp_x = [&](int xx) -> int{
        return (lower_bound(all(todos_x), xx) - todos_x.begin());
    };

    BIT yises;
    yises.init(todos_y.size());
    BIT xises;
    xises.init(todos_x.size());

    sort(rall(horizontais));
    sort(rall(verticais));
    
    int ans = (h+1) * (v+1);

    for (auto [y1,y2] : horizontais){
        int c2 = comp_y(y2);
        int res = yises.sum(c2);
        ans += res;
        yises.upd(c2, 1);
    }
    for (auto [x1,x2] : verticais){
        int c2 = comp_x(x2);
        int res = xises.sum(c2);
        ans += res;
        xises.upd(c2, 1);
    }

    cout << ans << endl;
}