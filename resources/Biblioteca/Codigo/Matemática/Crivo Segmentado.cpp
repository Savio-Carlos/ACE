// Crivo Segmentado
//
// Marca quais numeros no intervalo [L, R] sao primos
// usar quando R eh muito grande para um crivo normal mas R - L eh pequeno
//
// Complexidades:
// O((R - L + 1) log(log(R)) + sqrt(R) log(log(sqrt(R))))
//
// segmentedSieve(L, R) -> retorna vetor onde isPrime[i] indica se (i + L) eh primo

vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;

    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes){
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i){       
            isPrime[j - L] = false;
        }
    }
    if (L == 1) isPrime[0] = false;
    
    //para pegar os primos basta fazer i + L no vetor de isprime 
    return isPrime;
}
