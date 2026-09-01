#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    fastio;
    int f, n; cin >> f >> n;
    map<int, int> mp;
    vector<int> amigos;
    for(int i = 0; i < n; i++){
        int amg, qtd; cin >> amg >> qtd;
        mp[amg] = qtd;
        amigos.push_back(amg);
    }

    map<int, bool> vaiounao;
    map<int, int> diff;
    map<int, int> indeg;
    map<int, vector<int>> grafo;
    map<int, pair<int, int>> horario;
    for(int i = 0; i < n; i++){
        char op; cin >> op;
        if(op == 'A'){
            int ini; cin >> ini;
            int fim; cin >> fim;
            fim += ini;
            horario[amigos[i]] = {ini, fim};
            // diff[ini]+= mp[amigos[i]];
            // diff[fim]-= mp[amigos[i]]; 
            vaiounao[amigos[i]] = true;
        }else if(op == 'D') vaiounao[amigos[i]] = false;
        else{
            int outroamigo; cin >> outroamigo;
            indeg[amigos[i]]++; 
            grafo[outroamigo].push_back(amigos[i]);
        }
    }

    queue<int> q;
    for(auto amg : amigos){
        if(indeg[amg] == 0 && vaiounao[amg]){
            q.push(amg);
        }
    }


    while(!q.empty()){
        int v = q.front(); q.pop();
        auto [ini, fim] = horario[v];
        diff[ini]+= mp[v];
        diff[fim]-= mp[v]; 
        for(auto u : grafo[v]){
            if(--indeg[u] == 0){
                horario[u] = {ini, fim};
                q.push(u);
            }
        }
    }

    int sum = 0, ans = 0;
    for(auto [_, u] : diff){
        sum += u;
        ans = max(ans, sum);
    }

    cout << ans << endl;

    
}