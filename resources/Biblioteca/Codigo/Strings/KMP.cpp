// KMP
//
// Prefix function: para cada posicao i, calcula o tamanho do maior
// prefixo proprio de s[0..i] que tambem e sufixo de s[0..i]
// Usado pra casamento de padrao (concatenar padrao + separador + texto
// e olhar onde pi[i] == |padrao|)
//
// Complexidades:
// prefix_function - O(|s|)
// kmp             - O(|s|)
//
// prefix_function(s) e kmp(s) sao duas implementacoes equivalentes,
// retornam o vetor pi onde pi[i] e o tamanho do maior prefixo=sufixo de s[0..i]
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

//implementacao minha
vector<int> kmp(string s){
    int n = s.size(), pfxlen = 0;
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++){
        if (s[i] == s[pfxlen]) a[i] = ++pfxlen;
        else if (pfxlen){
            pfxlen = a[pfxlen-1];
            i--;
        }
        else a[i] = 0;
    }
    return a;
}
