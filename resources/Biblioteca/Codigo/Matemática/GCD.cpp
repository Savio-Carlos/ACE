// GCD e LCM (MDC e MMC)
//
// Calcula o maximo divisor comum e o minimo multiplo comum de dois numeros
//
// Complexidades:
// gcd - O(log(min(a, b)))
// mmc - O(log(min(a, b)))

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mmc(int a, int b) {
    return a / gcd(a, b) * b;
}