#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

int helper(int a, char efeito){
    if(efeito == 'N') return a;
    if(efeito == 'D') return 2*a;
    if(efeito == 'B') return a+3;
    else return 10-a;
}

signed main(){
    fastio;
    int n; cin >> n;
    int qtd1 = 0, qtd2 = 0, pontuacao1 = 0, pontuacao2 = 0;
    for(int i = 0; i < n; i++){
        int a;
        char efeito;
        cin >> a >> efeito;
        int amnt1 = helper(a, efeito);
        cin >> a >> efeito;
        int amnt2 = helper(a, efeito);
        if(amnt1 > amnt2){
            qtd2 = 0;
            pontuacao1 += 2, qtd1++;
            if(qtd1%3 == 0) pontuacao1 += 3;
        }
        else if(amnt1 < amnt2){
            qtd1 = 0;
            pontuacao2 += 2, qtd2++;
            if(qtd2%3 == 0) pontuacao2 += 3;
        }
        else{
            pontuacao1++, pontuacao2++;
            qtd1 = 0, qtd2 = 0;
        }
    }

    cout << pontuacao1 << " " << pontuacao2 << endl;
    if(pontuacao1 > pontuacao2) cout << "Minez\n";
    else if(pontuacao2 > pontuacao1) cout << "Mandelli\n";
    else cout << "Empate\n";
}