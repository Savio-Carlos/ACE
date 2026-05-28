#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
// using namespace dbg;

#define DEBUG

#ifdef DEBUG
    #define fastio (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

/*
o bispo imita o comportamento de arithimetic billiards de tamanho n-1 m-1
a = n-1
b = m-1
considerando o plano infinito

o bispo vai parar no (L,L) onde L = lcm(a,b)
ele percorre L horizontalmente e L verticalmente
contar intersecoes
g = gcd(a,b)
arithimetic billiards diz que o numero de bounces nos dois lados de tamanho a = a/g-1
similarmente, nos dois lados de tamanho b -> b/g-1
numero de intersecoes totais seria a/g-1 * b/g-1, considerando que conta dos dois lados, divide isso por 2

+1 inicial pois fizemos n-1 m-1
*/
signed main(){
    fastio;
    int n, m;
    
    while(cin >> n >> m){
        int a = n-1;
        int b = m-1;
        int g = gcd(a,b);
        int l = lcm(a,b);
 
        int hor = l/a - 1;
        int ver = l/b - 1;
        int visited = l+1;
        visited -= (hor*ver) / 2;
        cout << n*m - visited << endl;
    }
}