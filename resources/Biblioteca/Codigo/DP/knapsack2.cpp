// Knapsack II (indexado por valor)
//
// Inverte os eixos do knapsack classico: dp[i][val] = menor peso necessario
// para atingir exatamente `val` de valor usando os itens [1, i]. Util quando
// a soma dos valores (MAXV) e pequena mas a capacidade W e grande
//
// Complexidades:
// pd - O(n * MAXV)
//
// chamar pd(n, val) para val de sum(arr) ate 0 e pegar o maior val tal que
// pd(n, val) <= W; nao esquecer memset(dp, -1, sizeof(dp))
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