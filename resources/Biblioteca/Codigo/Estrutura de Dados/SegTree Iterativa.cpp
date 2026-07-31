// SegTree Iterativa (bottom-up, sem recursao)
//
// Segment tree iterativa para RMQ (maximo) em range, com update pontual
// (seta, nao soma). 0-indexada. Mais rapida na pratica que a recursiva
// por nao ter overhead de chamadas, mas nao suporta lazy propagation.
//
// Complexidades:
// build  - O(n)
// query  - O(log n)
// update - O(log n)
//
// build(n, v)  -> inicializa com array v de tamanho n (arredonda p/ potencia de 2 por dentro)
// query(a, b)  -> maximo em [a,b], 0-indexado; retorna 0 se a>b
// update(i, x) -> seta (nao soma) a posicao i para x

namespace SegTree {
    int n;
    int pot2;
    vector<int> tree;

    void build(int n2, int* v2) {
        n = n2;
        pot2 = 1;
        while (pot2 < n) pot2 <<= 1;
        tree.assign(2 * pot2, 0);
        for (int i = 0; i < n; ++i) tree[pot2 + i] = v2[i];
        for (int i = pot2 - 1; i >= 1; --i) tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    int query(int a, int b) {
        if (a > b) return 0;
        a += pot2; b += pot2;
        int res = 0;
        while (a <= b) {
            if (a & 1) res = max(res, tree[a++]);
            if (!(b & 1)) res = max(res, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return res;
    }

    void update(int i, int x) {
        int p = i + pot2;
        tree[p] = x;
        p >>= 1;
        while (p >= 1) {
            tree[p] = max(tree[2*p], tree[2*p+1]);
            p >>= 1;
        }
    }
}