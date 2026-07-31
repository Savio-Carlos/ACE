// Manacher
//
// Acha, pra cada posicao, o tamanho do maior palindromo centrado ali
// (contando pares e impares). Usado pra achar todos os palindromos de uma string
// O main mostra como reconstruir as substrings, mas usa substr() a cada
// palindromo, entao nao e eficiente (O(tamanho) por chamada)
//
// Complexidades:
// manacher_odd - O(|s|)
// manacher     - O(|s|)
//
// manacher_odd(s) retorna p, onde p[i]-1 e o raio do maior palindromo
// de tamanho impar centrado em i (sem separadores)
// manacher(s) insere separadores '#' entre os caracteres e chama manacher_odd;
// retorna mnc onde mnc[i]-1 e o tamanho do maior palindromo (par ou impar)
// centrado na posicao i da string transformada

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return res;
}

signed main() {
    winton;
    string s;
    cin >> s;

    vector<int> mnc = manacher(s);
    vector<pair<int,int>> palindromes;
    for (int i = 0; i < mnc.size(); i++){
        if (mnc[i]-1 > 0){
            palindromes.push_back({mnc[i]-1,i});//guarda os palindromes com {tamanho, centro}
        }
    }

    sort(rall(palindromes));//ordena pelos maiores(opicional ne)
    for (auto &[size, centro] : palindromes){

        string pos;
        int st = ((centro - size)/2);
        pos = s.substr(st, size); //gera a substring daquele palindrome
    }
}