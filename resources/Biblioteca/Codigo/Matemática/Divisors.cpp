// Divisores
//
// Calcula todos os divisores de tot
//
// Complexidades:
// O(sqrt(tot))
vector<int> divisors;
for (int i = 1; i * i <= tot; ++i) {
if (tot % i == 0) {
    divisors.push_back(i);
    if (i * i != tot) divisors.push_back(tot / i);
}