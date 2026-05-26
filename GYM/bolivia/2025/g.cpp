#include <bits/stdc++.h>
using namespace std;


#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 1e5+7;

vector<int> fatores[4*MAX], l_fatores[4*MAX];

struct SegTree {
    int tree[4*MAX], lazy[4*MAX]; // soma
    int n;

    void build(int node, int l, int r){
        lazy[node] = -1;
        tree[node] = 0;
        if (l == r) return;
        int m = (l+r)/2;
        build(2*node, l, m);
        build(2*node+1, m+1, r);
    }

    void init(int _n){
        n = _n;
        build(1, 0, n-1);
    }

    void prop(int node, int l, int r){
        if (lazy[node] != -1){
            tree[node] = lazy[node] * (r - l + 1);
            
            // atualiza os fatores
            fatores[node] = l_fatores[node];

            if (l != r){

                // Propaga
                l_fatores[2*node] = l_fatores[node];
                l_fatores[2*node+1] = l_fatores[node];

                lazy[2*node] = lazy[node];
                lazy[2*node+1] = lazy[node];
            }

            // limpa fatores
            l_fatores[node].clear();

            lazy[node] = -1;
        }
    }

    int soma(vector<int> s){
        int aux = 0;
        for(auto w:s) aux += w;
        return aux;
    }

    void update(int a, int b, vector<int> f, int node = 1, int l = 0, int r = MAX-1){
        if (node == 1) r = n-1;
        prop(node, l ,r);

        if (a > r or b < l) return;

        // Contido no intervalo
        if (a <= l and r <= b){
            lazy[node] = soma(f);

            l_fatores[node] = f;

            prop(node,l,r);

            // for(auto fat:fatores[node]) cout << fat << "f ";
            // for(auto fat:l_fatores[node]) cout << fat << "f2 ";
            // cout << endl;
            // cout << "soma " << lazy[node] << endl;

            return;
        }

        int m = (l+r)/2;
        update(a,b,f,2*node,l,m);
        update(a,b,f,2*node+1,m+1,r);

        tree[node] = tree[node*2] + tree[node*2+1];

        fatores[node].clear();

        // int s1 = fatores[node*2].size(), s2 = fatores[node*2+1].size();
        // int i = 0, j = 0;
        // while(i < s1 && j < s2){
        //     int esq = fatores[node*2][i];
        //     int dir = fatores[node*2+1][j];
        //     if(esq < dir){
        //         fatores[node].push_back(esq);
        //         i++;
        //     } else {
        //         fatores[node].push_back(dir);
        //         j++;
        //     }
        // }

        // while(i < s1){
        //     int esq = fatores[node*2][i];
        //     fatores[node].push_back(esq);
        //     i++;
        // }

        // while(j < s2){
        //     int dir = fatores[node*2+1][j];
        //     fatores[node].push_back(dir);
        //     j++;
        // }

        // for(auto fat:fatores[node*2]){
        //     fatores[node].push_back(fat);
        // }

        // for(auto fat:fatores[node*2+1]){
        //     fatores[node].push_back(fat);
        // }

        // sort(all(fatores[node]));

    }

    int query(int a, int b, int node = 1, int l = 0, int r = MAX-1){
        if (node == 1) r = n-1;
        prop(node,l,r);
        if (a > r or b < l) return 0;
        if (a <= l and r <= b) return tree[node];
        int m = (l+r)/2;
        return query(a,b,2*node,l,m) + query(a,b,2*node+1,m+1,r); 
    }

    vector<int> query_f(int a, int b, int node = 1, int l = 0, int r = MAX-1){
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r or b < l) return {};
        if (a <= l and r <= b) return fatores[node];
        int m = (l+r)/2;

        vector<int> esq = query_f(a,b,2*node,l,m), dir = query_f(a,b,2*node+1,m+1,r);

        if(!esq.empty()) return esq;
        return dir;

        // if(query(a,b,2*node,l,m).empty())

        // return query_f(a,b,2*node,l,m) + query_f(a,b,2*node,m+1,r); 
    }

};

vector<int> factor(int n){
    vector<int> primes;
    for (int p = 2; p * p <= n; p++){
        while(n%p == 0){
            primes.push_back(p);
            n /= p;
        }
    }
    if (n > 1) primes.push_back(n);
    return primes;
}

signed main(){
    fastio;
    int n, q;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    SegTree seg;

    seg.init(n);

    for(int i = 0; i < n; i++){
        seg.update(i, i, factor(v[i]));
    }


    cin >> q;
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;

        // cout << "debug" << endl;
        // for(int i = 0; i < 4 * n; i++){
        //     for(auto fat:fatores[i]){
        //         cout << fat << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "debug soma " << endl;
        // for(int i = 0; i < 4 * n; i++){
        //         cout << seg.tree[i] << " ";

        // }
        // cout << endl;

        // cout << "debug lazy " << endl;
        // for(int i = 0; i < 4 * n; i++){
        //         cout << seg.lazy[i] << " ";

        // }
        // cout << endl;



        if(op == 1){
            int pos;
            cin >> pos;
            vector<int> a = seg.query_f(pos-1, pos-1);

            // for (auto u : a) cout << "TIRAAAAAAAA " << u  << " "<< pos-1 << endl;
            if(!a.empty()) a.pop_back();
            // for (auto u : a) cout << "TIRAAAAAAAA " << u  << " "<< pos-1 << endl;
            seg.update(pos-1, pos-1, a);
        }

        if(op == 2){
            int l, r;
            cin >> l >> r;
            cout << seg.query(l-1, r-1) << endl;
        }

        if(op == 3){
            int l, r, val;
            cin >> l >> r >> val;
            seg.update(l-1, r-1, factor(val));

            // cout << "fats ";
            // for(auto fat:factor(val)){
            //     cout << fat << " ";
            // }
            // cout << endl;

        }
    }
}