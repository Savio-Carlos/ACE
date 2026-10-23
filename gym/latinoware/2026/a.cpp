#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<string> nome(n);
    vector<int> pontuacao(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> nome[i];
        int questoes;
        cin >> questoes;
        int total = questoes * 10;
        vector<int> aux(6);
        for(int j = 0; j < 6; j++){
            cin >> aux[j];
        }
        sort(all(aux));
        for(int j = 1; j < 5; j++){
            total += aux[j];
        }
        pontuacao[i] = total;
    }

    // for(int i = 0; i < n; i++){
    //     cout << nome[i] << " " << pontuacao[i] << endl;
    // }


    int maior = 0, maior2 = 0, maior3 = 0;
    for(int i = 0; i < n; i++){
        if(pontuacao[i] > maior) maior = pontuacao[i];
    }

    set<int> pego;
    int cnt = 0;
    while(cnt < 3){
        int maior = -1;
        for(int i = 0; i < n; i++){
            if(!pego.count(pontuacao[i]) && pontuacao[i] > maior){
                maior = pontuacao[i];
            }
        }

        if(maior == -1) break;
        pego.insert(maior);

        for(int i = 0; i < n; i++){
            if(pontuacao[i] == maior){
                cout << nome[i] << " " << pontuacao[i] << endl;
                cnt++;
            }
        }
    }

}