// Z-function
//
// Complexidades:
// z_function - O(|s|)
//
// z_function(s) retorna z, onde z[i] e o tamanho do maior prefixo comum
// entre s e o sufixo de s comecando em i (z[0] fica 0 por convencao, nao e usado)
// pra casamento de padrao: concatenar padrao + separador + texto e checar z[i] == |padrao|
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])z[i]++;
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}