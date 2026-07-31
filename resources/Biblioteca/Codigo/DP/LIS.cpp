// LIS (Longest Increasing Subsequence)
//
// Calcula o tamanho da maior subsequencia NAO decrescente de `a` (permite
// elementos iguais); para subsequencia estritamente crescente troque
// upper_bound por lower_bound. Ao final, lis.size() e a resposta (o vetor
// lis nao guarda a subsequencia em si, so os menores finais de cada tamanho)
//
// Complexidades:
// O(n log(n))

for (auto x : a){
    int pos = upper_bound(all(lis), x) - lis.begin();
    if (pos == (int)lis.size()) lis.push_back(x);
    else lis[pos] = x;
}
