// Kadane
//
// Maior soma de subarray continuo (nao vazio) de um vetor com valores
// possivelmente negativos: para cada posicao decide entre estender o
// subarray atual ou recomecar nela.
//
// Complexidades:
// O(n)

int kadane(const & vector<int> x) {
	int sum = x[0];
	int mx = x[0];
	for (int i = 1; i < x.size(); i++) {
		sum = max(sum + x[i], x[i]);
		mx = max(mx, sum);
	}
	return mx;
}

