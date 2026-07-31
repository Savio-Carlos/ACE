// BIT (Fenwick Tree) - soma em range
//
// Duas variantes:
// struct BIT - upd/sum classicos, 1-indexada (posicoes validas 1..n)
// struct Bit - interface 0-indexada (converte pra 1-indexada por dentro),
//              com construtor O(n) a partir de um vector e query de range
//
// Complexidades:
// init/construtor  - O(n)
// upd/update       - O(log n)
// sum/pref/query   - O(log n)
//
// BIT: bit.init(n); depois bit.upd(x, v) soma v na posicao x (1-indexada,
//      x em [1,n]); bit.sum(x) retorna a soma do prefixo [1, x]
// Bit: Bit b(n) ou Bit b(vector<int>&) pra construir O(n);
//      b.update(i, x) soma x na posicao i (0-indexada);
//      b.pref(i) soma o prefixo [0, i]; b.query(l, r) soma [l, r] (0-indexada)
struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n = 0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, int x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}

	int pref(int i) { // soma [0, i]
		int ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	int query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
};