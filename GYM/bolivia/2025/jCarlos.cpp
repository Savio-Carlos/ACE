#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int a, b;
    
    while(cin >> a >> b){
        int aa = a-1;
        int bb = b-1;
        
        int g = gcd(aa,bb);
        int v = aa*g*bb;
        cout << a*b - v << endl;
        
        cout << v << endl;
    }
        
    // pior que tem muita informacao nesse zero kkkkkkkkkkk
    // da onde vc tirou o 2?
    //eu tava contando as diagonais duas vezes
    //nos dois sentidos
    // legal 

}