// Random
//
// Gerador de numeros aleatorios (Mersenne Twister 64 bits) seedado com o clock,
// mais um uniform_int_distribution pra sortear inteiros num intervalo
//
// dist(rng) retorna um long long uniforme em [0, n]
// trocar os limites de dist conforme o intervalo desejado

#include <random>
#include <chrono>

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> dist(0, n);//valores min e max

int x = dist(rng);
