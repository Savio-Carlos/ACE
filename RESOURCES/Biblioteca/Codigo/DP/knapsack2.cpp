//Knapsack II
int dp[MAXN][MAXV];
int n, W;
int arr[MAXN], weights[MAXN];

int pd(int i, int val){
    if(val < 0) return INF;
    if(val == 0) return 0;
    if(i == 0) return INF;

    if(dp[i][val] != -1) return dp[i][val];

    return dp[i][val] = min(pd(i-1, val - arr[i]) + weights[i], pd(i-1, val));
}