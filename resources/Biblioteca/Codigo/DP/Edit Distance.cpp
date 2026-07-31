// Distancia de Edicao (apenas insercao/remocao)
//
// dp[i][j] = tamanho da LCS entre s[0..i) e t[0..j) (mesma recorrencia de
// Lcs.cpp); como so sao permitidas insercoes e remocoes (sem substituicao),
// a distancia de edicao entre s e t e dada por n + m - 2*dp[n][m]
//
// Complexidades:
// dp - O(n*m)
int dp[MAX][MAX];

string s, t;
cin >> s >> t;
int n = s.length();
int m = t.length();
for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}