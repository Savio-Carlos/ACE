#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int divisors(int x){
    vector<int> d;
    int sum = 0;
    if (x == 1) return 0;
    for (int i = 1; i*i <= x; i++){
        if (x%i == 0){
            d.push_back(i);
            sum += i;
            if (i != 1 && x/i != i){
                d.push_back(x/i);
                sum += x/i;
            } 
        } 

    }
    return sum;
}

string tp[] = {"perfecto", "romantico", "abundante", "complicado"};

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<string>> ans(n);
    map<int,vector<int>> mp;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        auto sum = divisors(a[i]);
        // cout << "sum: " << sum << " a[i]: " << a[i] << endl;
        int sumd = divisors(sum);
        // cout << "sumd: " << sumd << endl;
        if (sum == a[i]) ans[i].push_back(tp[0]);
        if (sumd == a[i] && sum != a[i]) ans[i].push_back(tp[1]);
        if (sum > a[i]) ans[i].push_back(tp[2]);
        if (ans[i].empty()) ans[i].push_back(tp[3]);
    } 

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
        for (auto u : ans[i]) cout << u << " ";
        cout << endl;
    }
}