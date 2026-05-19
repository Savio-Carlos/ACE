#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define ld long double

signed main(){
    fastio;
    int n, c;
    cin >> n >> c;
    vector<int> predios(n), cons(n);

    for(int i = 0; i < n; i++){
        cin >> predios[i];
    }

    for(int i = 0; i < c; i++){
        int dia, andares;
        cin >> dia >> andares;
        cons[--dia] += andares;
    }

    int acc = 0;
    for(int i = n - 1; i >= 0; i--){
        acc += cons[i];
        predios[i] += acc;
    }


    // for(int i = 0; i < n; i++){
    //     cout << predios[i] << " ";
    // } cout << endl;


    stack<int> pilha;
    for(int i = 0; i < n; i++){
        int andares = 0;
        
        if(i != 0) cout << pilha.size() << endl;

        while(!pilha.empty() && pilha.top() <= predios[i]){
            pilha.pop();
            andares++;
        }

        pilha.push(predios[i]);
    }

}