//Achar prefixos que formam a string toda
const int MOD = 1e9+7;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash {
	static int P;
	vector<int> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	int operator()(int l, int r) { // retorna hash s[l...r]
		int hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|
 
 
void solve() {
    string s; cin >> s;
    str_hash<MOD> hasher(s);
    int n = s.size();
    for(int i = 1; i <= n; i++){
        if(i == n) cout << n << endl;
        else{
            int h1 = hasher(0, n-i-1);
            int h2 = hasher(i, n-1);
            if(h1 == h2){
                cout << i << " ";
            }
        }
    }
}