//Order Statistic Tree
//order_of_key(x): counts the number of elements in the set that are strictly less than x.
//find_by_order(k): similar to find, returns the iterator corresponding 
//to the k-th lowest element in the set (0-indexed).
//pode dar insert, erase, size e empty

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Tree<int> t;
//Tree<pair<int, int>> t;