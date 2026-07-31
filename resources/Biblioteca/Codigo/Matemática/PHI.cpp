// Função de Euler (Phi)
//
// phi[i] = quantidade de numeros de 1 ate i que sao coprimos com i
// precomputePHI precisa ser chamado antes de usar phi
//
// Complexidades:
// precomputePHI - O(MAX log(log(MAX)))
int phi[MAX];

void precomputePHI(){
    for (int i = 0; i < MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}