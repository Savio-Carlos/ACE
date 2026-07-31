// Order Statistic Tree (policy tree do pb_ds)
//
// Set ordenado (sem duplicatas) que alem das operacoes normais de um
// std::set suporta consulta de rank/posicao em O(log n).
//
// Complexidades:
// insert/erase/find - O(log n)
// order_of_key(x)    - O(log n): qtd de elementos estritamente menores que x
// find_by_order(k)   - O(log n): iterator do k-esimo menor elemento (0-indexado)
//
// Tree<int> t;                // uso identico a um set<int>: insert, erase, size, empty
// Tree<pair<int,int>> t;      // pra permitir "duplicatas", use pair<valor, id_unico>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;