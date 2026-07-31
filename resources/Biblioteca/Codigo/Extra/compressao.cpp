// Compressao de Coordenadas
//
// Mapeia os valores de v pra indices [0, m) preservando a ordem relativa
// (m = quantidade de valores distintos)
//
// Complexidades:
// build - O(n log(n))
// comp(x) - O(log(n))
//
// build direto: comp[i] = indice de v[i] em todos (vetor ordenado e sem duplicatas)
// ou use a lambda comp(x) pra comprimir um valor qualquer on-the-fly

vector<int> v(n);
vector<int> todos;
for (int i = 0; i < n; i++){
    cin >> v[i];
    todos.push_back(v[i]);
}

sort(all(todos));
todos.erase(unique(all(todos)), todos.end());
int m = todos.size();

vector<int> comp(n);
for (int i = 0; i < n; i++){
    comp[i] = lower_bound(all(todos), v[i]) - todos.begin();
}

auto comp = [&](int x) -> int{
    return (lower_bound(all(todos),x) - todos.begin());
};