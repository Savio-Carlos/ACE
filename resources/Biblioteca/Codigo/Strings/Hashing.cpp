// String Hashing
//
// Complexidades:
// construtor - O(|s|)
// operator() - O(1)

// ====================================================================
// CUIDADO: as duas formas de prefix hash 
// ====================================================================
//
// FORMA 1 - "potencia por posicao" (e a usada nas structs deste arquivo):
//     h[i+1] = h[i] + s[i]*P^i
//     get_hash(l, len) = h[l+len] - h[l]
//
//   O valor devolvido NAO e o hash da substring: e o hash dela
//   MULTIPLICADO por P^l. Duas substrings IGUAIS em posicoes DIFERENTES
//   devolvem valores DIFERENTES.
//   => nao da pra usar direto como chave de map/set, nem comparar duas
//      substrings que comecam em posicoes diferentes. Por isso o
//      equal_substrings/rabin_karp aqui precisam multiplicar um dos
//      lados por p_pow pra compensar o offset.
//
//   Comparar l1 com l2 (mesmo len):  h(l1)*P^l2 == h(l2)*P^l1
//
//   Chave canonica sem inverso modular (so quando todas as substrings
//   tem o MESMO len, que e o caso tipico de varrer a string por tamanho):
//       key = get_hash(i, len) * p_pow[n-1-i] % MOD
//   vira sum s[i+k]*P^(n-1+k), que nao depende de i. Precisa p_pow ate
//   o indice n-1 (as structs abaixo ja tem).
//
// FORMA 2 - Horner (recomendada pro caso geral, ver struct no fim):
//     h[i+1] = h[i]*P + s[i]
//     get_hash(l, len) = h[l+len] - h[l]*P^len
//
//   O valor depende SO do conteudo da substring. Da pra usar como chave
//   de map, comparar posicoes quaisquer, e equal_substrings vira ==.
//   Custo: 1 mult + 1 mod a mais por query (irrelevante perto do map) e
//   p_pow precisa ter tamanho n+1, porque agora e indexado por len (que
//   pode chegar a n) e nao por posicao.
//
// QUANDO A FORMA 1 AINDA E MELHOR:
//   na forma 1 a contribuicao de cada posicao (s[i]*P^i) nao depende de
//   nenhuma fronteira de substring, entao ela e "somavel":
//     - BIT/SegTree com update de ponto: o hash do range e uma soma pura.
//       (na forma Horner o no precisa guardar (hash, len) e o merge vira
//        left.hash*P^right.len + right.hash)
//     - hash de um CONJUNTO qualquer de posicoes, nao so de um intervalo.
//   Fora esses dois casos, use a forma 2.
//
// ANTI-HASH: com 1 mod so e base fixa da pra ser hackado. 
//   mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//   const int P = uniform_int_distribution<int>(256, MOD-2)(rng);
// ====================================================================

//string matching
vector<int> rabin_karp(string const& s, string const& t) {
    int S = s.size(), T = t.size();
        
    vector<int> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
    
    vector<int> h(T + 1, 0); 
    for (int i = 0; i < T; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD; //hash do texto(vetor a)
    
    int h_s = 0; 
    for (int i = 0; i < S; i++) h_s = (h_s + (s[i]- 'a' + 1) * p_pow[i]) % MOD; //hash da string s (vetor b)
    
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        int cur_h = (h[i+S] + MOD - h[i]) % MOD;
        if (cur_h == h_s * p_pow[i] % MOD) occurrences.push_back(i);
    }
    return occurrences;
}


//struct para um vetor de strings
//consegue retornar um vetor sem as strings que sao substrings de outras
//consegue checar se o prefixo de uma string e o sufixo de outra

struct hashing {
    int p_pow[MAX]; 
    vector<int> hashes[11];
    vector<string> strings;
    int n;
    
    hashing(int _n, vector<string> _a) : n(_n), strings(_a) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < MAX; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < n; i++)hashes[i] = calcHash(strings[i]);
    }

    vector<string> trim(){
        vector<string> ret;
        //funcao pra remover do vetor original as strings que sao substrings de outras
        //nao preciso delas pra fazer a verificacao depois
        set<int> occurrences;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                int S = strings[i].size(), T = strings[j].size();
                int h_s = hashes[i][S];
                for (int k = 0; k + S - 1 < T; k++) {
                    int cur_h = (hashes[j][k+S] + MOD - hashes[j][k]) % MOD;
                    if (cur_h == h_s * p_pow[k] % MOD) occurrences.insert(i);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (occurrences.find(i) != occurrences.end()) continue;
            ret.push_back(strings[i]);
        }
        debug(occurrences);
        return ret;
    }
    
    vector<int> calcHash(string s){
        vector<int> h(s.size() + 1, 0); 
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
        return h;
    }
    
    int get_hash(int l, int len, int idx){
        int r = l + len;
        return ((hashes[idx][r] + MOD - hashes[idx][l]) % MOD);
    }

    bool equal_substrings(int len, int i, int j) {
        if (!len) return true;

        int h1 = get_hash(0, len, i);
        int h2 = get_hash(strings[j].size() - len, len, j);

        int left  = (h1 * p_pow[strings[j].size()-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

//struct de hashing pra uma string so
struct hashing {
    vector<int> h, p_pow;
    string s;
    int n;
    
    hashing(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size(), 0) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    

    int get_hash(int l, int len){
        int r = l + len;
        return ((h[r] + MOD - h[l]) % MOD);
    }

    bool equal_substrings(int len) {
        if (!len) return true;

        int h1 = get_hash(0, len);
        int h2 = get_hash(n - len, len);

        int left  = (h1 * p_pow[n-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

//FORMA 2 (Horner) - hash de uma string so
//get_hash devolve valor canonico: substrings iguais => hashes iguais,
//independente da posicao. Pode jogar direto em map/set.
struct hashing_horner {
    vector<int> h, p_pow;
    string s;
    int n;

    hashing_horner(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size()+1, 0) {}

    void build(){
        p_pow[0] = 1;
        //p_pow indexado por LEN, entao vai ate n (e nao ate n-1)
        for (int i = 1; i <= n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < n; i++) h[i+1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
    }

    //hash de s[l .. l+len-1]
    int get_hash(int l, int len){
        return ((h[l+len] - h[l] * p_pow[len] % MOD) + MOD) % MOD;
    }

    bool equal_substrings(int i, int j, int len){
        return get_hash(i, len) == get_hash(j, len);
    }
};

//double mod hashing
struct hashing {
    string s;
    int n;
    vector<int> h1, h2;
    vector<int> p1, p2;

    hashing(const string &_s) : s(_s) {
        n = (int)s.size();
        h1.assign(n+1, 0);
        h2.assign(n+1, 0);
        p1.assign(n+1, 0);
        p2.assign(n+1, 0);
    }

    void build() {
        p1[0] = 1;
        p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i-1] * P1) % MOD1;
            p2[i] = (p2[i-1] * P2) % MOD2;
        }
        for (int i = 0; i < n; i++) {
            int val = (s[i] - 'a' + 1);
            h1[i+1] = (h1[i] + val * p1[i]) % MOD1;
            h2[i+1] = (h2[i] + val * p2[i]) % MOD2;
        }
    }

    pair<int,int> get_hash(int l, int len) {
        int r = l + len;
        int x1 = ((h1[r] - h1[l]) + MOD1) % MOD1;
        int x2 = ((h2[r] - h2[l]) + MOD2) % MOD2;
        return {x1, x2};
    }
};