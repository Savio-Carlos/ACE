#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)


struct frac {
    int num, den; 
    
    frac(int num_ = 0, int den_ = 1) : num(num_), den(den_){
        assert(den != 0);
        if(den < 0) num *= -1, den *= -1;
        int g = gcd(abs(num), den);
        num /= g, den /= g;
    }

    friend frac operator*(const frac& l, const frac& r){
        return {l.num*r.num, l.den*r.den};
    }

    friend frac operator*(int a, const frac& r){
        return {a*r.num, r.den};
    }

        friend frac operator+(const frac& l, const frac& r){
        return {l.num*r.den + l.den*r.num, l.den*r.den};
    }

    friend frac operator/(const frac& l, const frac& r){
        return {l.num*r.den, l.den*r.num};
    }
};

int A, B, C, L, R;

const int N = 3*100;
frac f(frac x){
    frac r(A*x*x + B*x + C);
    if (r.num < 0) r.num *= -1;
    return r;
}

frac integrate(int a, int b){
    frac s;
    frac h(b-a, N);
    for(int i = 0; i < N; i++){
        s = s + f(a + i*h)*(i%3 ? 3 : 2);
    }
    frac aa = ((f(a) + s + f(b))*3*h)/8;
    return aa;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        // int a, b, c, l, r;
        cin >> A >> B >> C >> L >> R;
        frac res = integrate(L,R);

        cout << res.num << "/" << res.den << endl;;
    }

}