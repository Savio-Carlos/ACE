#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 1e6+7;
const int MAX2 = 3e5+7;

int a[MAX2];

int qtd_cor[MAX];//quantas pedras tem qtd_cor x
int fatores[MAX];//quantas qtd_cores sao divisiveis pelo fator x

void divisores(int x, int id){
    for (int i = 1; i*i <= x; i++){
        if (x%i == 0){
            if (id == 1) fatores[i]++;  
            else fatores[i]--;

            if (i*i != x){
                if (id == 1) fatores[x/i]++;  
                else fatores[x/i]--;
            }
        }
    }
}

signed main(){
    fastio;
    int n, q; 
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        qtd_cor[a[i]]++;
    }

    for (int i = 1; i < MAX; i++){
        if (qtd_cor[i]) divisores(qtd_cor[i], 1);
    }

    // for (int i = 1; i <= 3; i++){
    //     debug(qtd_cor[i]);
    //     debug(i);
    //     debug(fatores[qtd_cor[i]]);
    //     cout << endl;
    // }

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i, y;
            cin >> i >> y;
            // debug(qtd_cor[a[i]]);
            // debug(a[i]);

            divisores(qtd_cor[a[i]], 0);
            // debug(fatores[1]);
            qtd_cor[a[i]]--;
            divisores(qtd_cor[a[i]], 1);
            a[i] = y;
            divisores(qtd_cor[y], 0);
            qtd_cor[y]++;
            divisores(qtd_cor[y], 1);
            // debug(fatores[1]);
        }
        else {
            int x;
            cin >> x;
            cout << fatores[x] << endl;
        } 
    }
}