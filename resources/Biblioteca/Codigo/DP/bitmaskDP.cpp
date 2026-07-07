//Bitmask DP

//hamiltonian path
const int MAXN = 20;
const int MAXM = (1<<20)+7;
const int MOD = 1e9+7;
vector<int> graph[MAXN];
int dp[MAXN][MAXM];
int n; 
 
int pd(int v, int mask){
	auto& p = dp[v][mask];
	//cout << v+1 << " " << mask << endl;
	if(v == n-1){
		//cout << v+1 << " " << mask << endl;
		return p = (mask ==((1<<n)-1));
	}
 
	if(p != -1) return p;
 
	int ans = 0;
	//cout << graph[v].size() << endl;
	for(auto u : graph[v]){
		//cout << u+1 << " " << mask << " " << (1<<u) << endl;
		if(!((mask>>u)&1)){
			int newmask = mask | (1 << u);
			ans = (ans + pd(u, newmask))%MOD;
		}
	}
	return p = ans;
}

//iterativo
dp[1][0] = 1;
for (int s = 2; s < 1 << city_num; s++) {
	// only consider subsets that have the first city
	if ((s & (1 << 0)) == 0) continue;
	// also only consider subsets with the last city if it's the full subset
	if ((s & (1 << (city_num - 1))) && s != ((1 << city_num) - 1)) continue;
	for (int end = 0; end < city_num; end++) {
		if ((s & (1 << end)) == 0) continue;
		// the subset that doesn't include the current end
		int prev = s - (1 << end);
		for (int j : come_from[end]) {
			if ((s & (1 << j))) {
				dp[s][end] += dp[prev][j];
				dp[s][end] %= MOD;
			}
		}
	}
}

//merging subsets O(n^3)
for (int mask = 0; mask < (1 << n); mask++) {
	for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
		int subset = mask ^ submask;
		// do whatever you need to do here
	}
}

//submasks
dp[1][0] = 1;
for (int s = 2; s < 1 << city_num; s++) {
	// only consider subsets that have the first city
	if ((s & (1 << 0)) == 0) continue;
	// also only consider subsets with the last city if it's the full subset
	if ((s & (1 << (city_num - 1))) && s != ((1 << city_num) - 1)) continue;
	for (int end = 0; end < city_num; end++) {
		if ((s & (1 << end)) == 0) continue;
		// the subset that doesn't include the current end
		int prev = s - (1 << end);
		for (int j : come_from[end]) {
			if ((s & (1 << j))) {
				dp[s][end] += dp[prev][j];
				dp[s][end] %= MOD;
			}
		}
	}
}