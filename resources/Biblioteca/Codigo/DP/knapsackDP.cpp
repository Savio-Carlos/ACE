// Knapsack 0/1 (recursivo)
//
// dp[i][w] = valor maximo obtido usando os itens [i, n) dado que ja foi
// usado w de peso, com capacidade total k
//
// Complexidades:
// pd - O(n*k)
//
// chamar pd(0, 0); nao esquecer memset(dp, -1, sizeof(dp))
int dp[MAXN][MAXM];

int n, k;
int pd(int w, int i){
    if(w > k) return -INF;
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    return dp[i][w] = max(pd(w+peso[i], i+1) + val[i], pd(w, i+1));
}