// Matrix Exponentiation
//
// matrix: struct que estende vector<vector<int>>, com multiplicacao
// (mod MOD) e exponenciacao rapida por operator^
//
// Complexidades:
// operator* (multiplicacao n x m por m x k) - O(n*m*k)
// operator^ (exponenciacao pra potencia e) - O(n^3 log(e))
//
// instancia: matrix m(n, m2) para uma matriz n x m2 zerada, ou
// matrix m(n, n, true) para a identidade n x n
// tambem constroi a partir de um vector<vector<int>> existente
// usa MOD global nas operacoes; operator^ assume matriz quadrada
struct matrix : vector<vector<int>> {
    int n, m;

    matrix(int n_, int m_, bool ident = false) : vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

    matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
    n(c.size()), m(c[0].size()) {}

    matrix operator*(const matrix &a) const {
        assert(m == a.n);
        matrix res(n, a.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a.m; j++){
                for (int k = 0; k < m; k++){
                    res[i][j] = (res[i][j] + ((*this)[i][k] * a[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    matrix operator^(int e) const {
        matrix res(n,n,true);
        matrix base = *this;
        while (e) {
            if (e&1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
};