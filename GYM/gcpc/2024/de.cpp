#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

const int MOD = 1000000007;

int add(int a, int b){
    a %= MOD; if(a < 0) a += MOD;
    b %= MOD; if(b < 0) b += MOD;
    return (a + b) % MOD;
}

int sub(int a, int b){
    a %= MOD; if(a < 0) a += MOD;
    b %= MOD; if(b < 0) b += MOD;
    return (a - b + MOD) % MOD;
}

int mul(long long a, long long b){
    a %= MOD; if(a < 0) a += MOD;
    b %= MOD; if(b < 0) b += MOD;
    return (int)((a * b) % MOD);
}

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
            s = add(s, bit[x]);
        }
        return s;
    }

    void upd(int x, int v){
        v %= MOD; if(v < 0) v += MOD;
        for(; x <= n; x += x&(-x)){
            bit[x] = add(bit[x], v);
        }
    }
};

int fastexpo(int a, long long b){
    a %= MOD; if(a < 0) a += MOD;
    int res = 1;
    while(b > 0){
        if(b & 1) res = mul(res, a);
        a = (int)((1LL*a*a) % MOD);
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m; cin >> n >> m;
    string t_str; cin >> t_str;
    long long p_num = 0;
    long long p_den = 1;
    bool after_dec = false;
    for(char c : t_str){
        if(c == '.'){
            after_dec = true;
            continue;
        }
        if(after_dec){
            p_num = (p_num * 10 + (c - '0'));
            p_den = (p_den * 10);
        }
    }
    if(p_den == 0) p_den = 1;
    int p_frac = mul(p_num, fastexpo((int)p_den, MOD-2));

    int P = sub(1, p_frac);
    int invP = fastexpo(P, MOD-2);

    BIT bit1, bit2;
    bit1.init(n);
    bit2.init(n);

    for(int i = 0; i < m; i++){
        char op; cin >> op;
        if(op != '?'){
            int b, x; cin >> b >> x;
            int left = mul(b, fastexpo(invP, x));
            int right = mul(b, fastexpo(P, x));  
            if(op == '+'){
                bit1.upd(x, left);
                bit2.upd(x, right);
            } else {
                bit1.upd(x, sub(0, left));
                bit2.upd(x, sub(0, right));
            }
        } else {
            int k; cin >> k;
            int pk = fastexpo(P, k);
            int leftsum = bit1.sum(k);
            int p1 = mul(pk, leftsum);

            int invPk = fastexpo(invP, k);
            int sumN = bit2.sum(n);
            int sumK = bit2.sum(k);
            int right = sub(sumN, sumK);
            int p2 = mul(invPk, right);

            int ans = add(p1, p2);
            cout << ans << '\n';
        }
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}
