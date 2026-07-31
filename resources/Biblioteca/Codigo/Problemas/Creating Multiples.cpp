// Creating Multiples
//
// Dado um numero de l digitos em base b, decide se e possivel diminuir um
// unico digito para tornar o numero multiplo de (b+1).
// Usa que base ≡ -1 (mod base+1), entao o resto e a soma alternada dos
// digitos; para cada posicao calcula quanto precisa reduzir aquele digito
// para zerar o resto.
//
// Complexidades:
// O(l)

signed main(){
    winton;
    int b, l;
    cin >> b >> l;
    vector<int> d(l);
    for(auto &u : d) cin >> u;
    int base = b+1;
    int resto = 0;
    for (int i = 0; i < l; i++) {
        int termo = d[i];
        if (!((l-1-i)&1)) {
            termo = -termo;
        }
        resto = (resto+termo % base + base) % base;
    }
    if (resto == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < l; i++) {
        int reducao;
        if ((l-1-i)&1) {
            reducao = resto;
        } 
        else reducao = base - resto;
 
        if (d[i] >= reducao) {
            cout << i + 1 << " " << d[i] - reducao << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;;
}