// BIT de Xor (Fenwick Tree)
//
// BIT 1-indexada (posicoes validas 1..n) que faz xor no intervalo.
//
// Complexidades:
// construtor - O(n)
// update - O(log(n))
// query  - O(log(n))
//
// Bit b(n); depois b.update(i, x) faz xor de x na posicao i (1-indexada);
// b.pref(i) retorna o xor do prefixo [1, i] (pref(0) = 0);
// b.query(l, r) retorna o xor do intervalo [l, r] (1-indexado)

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	void update(int i, int x) { // xor x na posicao i
		for (i; i <= n; i += i & -i) bit[i] ^= x;
	}
	int pref(int i) { // xor [0, i]
		int ret = 0;
		for (i; i; i -= i & -i) ret ^= bit[i];
		return ret;
	}
	int query(int l, int r) {  // xor [l, r]
        debug(pref(r), pref(l-1));
		return pref(r) ^ pref(l - 1); 
	}
};