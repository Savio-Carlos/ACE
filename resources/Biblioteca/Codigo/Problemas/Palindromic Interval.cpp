// Intervalo de String Palíndromico
//
// Acha o maior intervalo [l, i] de uma string que pode ser reordenado
// para formar um palindromo (no maximo 1 caractere com contagem impar).
// Usa bitmask de paridade por caractere (prefix XOR) e guarda a primeira
// posicao em que cada mascara apareceu; testa a propria mascara e as 26
// mascaras a 1 bit de distancia (permitindo 1 caractere impar).
//
// Complexidades:
// O(n * 26)
//
// Pode ser adaptado para contar quantos palindromos e possivel fazer

int size = (1<<26);
vector<int> first(size, -1);
int mask = 0;
first[0] = 0;
int ans = 1;
for (int i = 0; i < s.size(); i++) {
    int chab = s[i] - 'a';
    mask ^= (1 << chab);
    if (first[mask] != -1) ans = max(ans, (i - first[mask])+1);
    for (int k = 0; k < 26; ++k) {
        int targetmask = mask ^ (1 << k);
        if (first[targetmask] != -1) ans = max(ans, (i - first[targetmask])+1);
    }
    if (first[mask] == -1) first[mask] = i+1;
}