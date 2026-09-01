#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(x) cerr << #x << ": " << x << endl;

bool comparar(vector<string> &a, vector<string> &b){
    if(a.size() != b.size()) return false;
    if(a[0].size() != b[0].size()) return false;

    bool diff = false;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> order_original;
    for (int i = 1; i <= 4; i++) order_original.push_back(i);

    vector<string> original(n);
    for (auto &u : original) cin >> u;
    
    auto gira1 = [&](vector<string> &grid, vector<int> &order) -> pair<vector<int>, vector<string>>{
        auto novo_order = order;
        novo_order[0] = order[1];
        novo_order[1] = order[2];
        novo_order[2] = order[3];
        novo_order[3] = order[0];
        vector<char> todos;
        auto novo = grid;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                novo[i][j] = grid[j][n-i-1];
            }
        }
        return {novo_order, novo};
    };

    auto gira2 = [&](vector<string> &grid, vector<int> &order) -> pair<vector<int>, vector<string>>{
        auto novo = grid;
        auto novo_order = order;
        novo_order[0] = order[2];
        novo_order[1] = order[3];
        novo_order[2] = order[0];
        novo_order[3] = order[1];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                novo[i][j] = grid[n-i-1][m-j-1];
            }
        }
        return {novo_order, novo};
    };

    auto gira3 = [&](vector<string> &grid, vector<int> &order) -> pair<vector<int>, vector<string>>{
        auto novo = grid;
        auto novo_order = order;
        novo_order[0] = order[3];
        novo_order[1] = order[0];
        novo_order[2] = order[1];
        novo_order[3] = order[2];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                novo[i][j] = grid[m-j-1][i];
            }
        }
        return {novo_order, novo};
    };

    auto mirror = [&](vector<string> &grid, vector<int> &order) -> pair<vector<int>, vector<string>>{
        auto novo_order = order;
        novo_order[0] = order[1];
        novo_order[1] = order[0];
        novo_order[2] = order[3];
        novo_order[3] = order[2];
        auto novo = grid;
        for (int i = 0; i < n; i++){
            reverse(all(novo[i]));
        }
        return {novo_order, novo};
    };

    auto mirror_cima = [&](vector<string> &grid, vector<int> &order) -> pair<vector<int>, vector<string>>{
        auto novo_order = order;
        novo_order[0] = order[3];
        novo_order[1] = order[2];
        novo_order[2] = order[1];
        novo_order[3] = order[0];
        auto novo = grid;
        for (int i = 0; i < n; i++){
            novo[i] = grid[n-i-1];
        }
        return {novo_order, novo};
    };

    set<vector<int>> st;
    
    if (n == m){
        auto ordem = order_original;
        auto [or1,o1] = gira1(original, ordem); 
        // for (auto s : o1) debug(s); cout << endl;
        auto [mmo, mm] = mirror(o1,or1);
        auto [mmc, mc] = mirror_cima(o1,or1);
        auto [mmco,mcc] = mirror(mc,mmc);
        if (comparar(original, o1))st.insert(or1);
        if (comparar(original, mm))st.insert(mmo);
        if (comparar(original, mc))st.insert(mmc);
        if (comparar(original, mcc))st.insert(mmco);
    }

    if (n == m){
        auto ordem = order_original;
        auto [or2,o2] = gira2(original, ordem); 
        // for (auto s : o2) debug(s); cout << endl;
        auto [mmo, mm] = mirror(o2,or2);
        auto [mmc, mc] = mirror_cima(o2,or2);
        auto [mmco,mcc] = mirror(mc,mmc);
        if (comparar(original, o2))st.insert(or2);
        if (comparar(original, mm))st.insert(mmo);
        if (comparar(original, mc))st.insert(mmc);
        if (comparar(original, mcc))st.insert(mmco);

        
        //  for (auto s : o2) debug(s); cout << endl;
        //  for (auto s : mc) debug(s); cout << endl;
        //  for (auto s : mcc) debug(s); cout << endl;
    }

    if (n == m){
        auto ordem = order_original;
        auto [or3,o3] = gira3(original, ordem); 
        // for (auto s : o3) debug(s); cout << endl;
        auto [mmo, mm] = mirror(o3,or3);
        auto [mmc, mc] = mirror_cima(o3,or3);
        auto [mmco,mcc] = mirror(mc,mmc);
        if (comparar(original, o3))st.insert(or3);
        if (comparar(original, mm))st.insert(mmo);
        if (comparar(original, mc))st.insert(mmc);
        if (comparar(original, mcc))st.insert(mmco);
    }



        auto [mmo, mm] = mirror(original,order_original);
        auto [mmc, mc] = mirror_cima(original,order_original);
        auto [mmco,mcc] = mirror(mc,mmc);
        if (comparar(original, original))st.insert(order_original);
        if (comparar(original, mm))st.insert(mmo);
        if (comparar(original, mc))st.insert(mmc);
        if (comparar(original, mcc))st.insert(mmco);


    cout << st.size() << endl;




    // for (auto u : st){
    //     for (auto s : u) debug(s);
    //     cout << endl;
    // }
    // auto [or1, o1] = gira3(original, order_original); 
    // // gira3(); 
    // for (auto s : o1) debug(s); cout << endl;

    // mirror();
    // for (auto s : grid) debug(s);cout << endl;
    // mirror_cima();
    // for (auto s : grid) debug(s);cout << endl;

}

