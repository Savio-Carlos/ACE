// 3 Equações, 4 Variáveis
//
// Sistema de 3 equacoes lineares com 4 variaveis (n, e, w, s), onde s e
// livre. Minimiza o maior valor absoluto entre n, e, w, s: cada restricao
// |var| <= M vira um intervalo valido de s, intersecta os 4 intervalos e
// usa o ponto medio do intervalo resultante como resposta.
//
// Complexidades:
// por query - O(1)

// n(s) = r + s
// e(s) = (y+p-r)/2 - s
// w(s) = (y-p-r)/2 - s
// s(s) = s
 
// n(s) = a + s
// e(s) = b - s
// w(s) = c - s
// s(s) = s
 
// M = max{(|a+s|), (|b-s|), (|c-s|), (|s|)}
 
// |a+s| <= M    ->     -M-a <= s <= M-a
// |b-s| <= M    ->     -M+b <= s <= M+b
// |c-s| <= M    ->     -M+c <= s <= M+c
// |s|   <= M    ->     -M   <= s <= M
 
// achar o minimo e maximo do intervalo de s
 
// smin = max(-a,b,c,0)
// smax = max(-a,b,c,0)
signed main(){
    int q;
    cin >> q;
    while(q--){
        ld p, r, y;
        cin >> p >> r >> y;
        ld a = r;
        ld b = (y+p-r)/2;
        ld c = (y-p-r)/2;
 
        ld smin = max({-a,b,c,(ld)0.0});
        ld smax = min({-a,b,c,(ld)0.0});
 
        ld s = (smin+smax)/2;
 
        ld n = r+s;
        ld e = b-s;
        ld w = c-s;
 
        cout << fixed << setprecision(7) << n << ' ' << e << ' ' << s << ' ' << w << ' ' << endl;
    }
}