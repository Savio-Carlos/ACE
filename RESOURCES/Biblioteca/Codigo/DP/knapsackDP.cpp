//Knapsack recursivo
int dp[MAXN][MAXM];

int n, k;
int pd(int w, int i){
    if(w > k) return -INF;
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    return dp[i][w] = max(pd(w+peso[i], i+1) + val[i], pd(w, i+1));
}