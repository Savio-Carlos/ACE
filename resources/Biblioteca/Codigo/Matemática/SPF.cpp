// Smallest Prime Factor
//
// spf[i] = menor fator primo de i, usado para fatorar rapido
// build precisa ser chamado antes de factorize
//
// Complexidades:
// build - O(MAX log(log(MAX)))
// factorize - O(log(x))
//
// factorize(x) -> retorna os fatores primos de x (com repeticao)

int n, spf[MAX];

void build(){
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

vector<int> factorize(int x){
    vector<int> primes;
    while (x > 1){
        int p = spf[x];
        primes.push_back(p);
        while(x%p == 0) x/=p;
    }
    
    return primes;
}

// Numero de fatores primos diferentes
//
// pf[i] = quantidade de fatores primos DIFERENTES de i
// build depois buildspf, nessa ordem
//
// Complexidades:
// build - O(MAX log(log(MAX)))
// buildspf - O(MAX)
int spf[MAX], pf[MAX];

void build(){
    spf[1] = 1;
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

void buildspf(){
    for (int i = 2; i < MAX; i++){
        pf[i] = pf[i/spf[i]];
        if (spf[i/spf[i]] != spf[i]) pf[i]++;
    } 
}
