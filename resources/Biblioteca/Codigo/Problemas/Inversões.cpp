// Inversões
//
// Conta o numero de pares (i, j) com i < j e arr[i] > arr[j], via merge
// sort: durante o merge, toda vez que um elemento da metade direita e
// escolhido antes de um da esquerda, ele forma inversao com todos os
// elementos restantes da esquerda.
//
// Complexidades:
// O(n log n)

int countAndMerge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) left[i] = arr[i + l];
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    return res;
}

int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversions(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}