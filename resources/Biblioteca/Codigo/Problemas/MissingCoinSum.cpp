// Missing Coin Sum
//
// Dado um multiconjunto de n moedas, acha a menor soma positiva que nao
// pode ser formada com nenhum subconjunto delas. Ordena as moedas e
// mantem em "ans" o limite superior (exclusivo) do intervalo [0, ans-1]
// garantidamente formavel; se a proxima moeda for maior que ans, "ans" ja
// e a resposta, senao ela estende o intervalo alcancavel.
//
// Complexidades:
// O(n log n) (dominado pelo sort)

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > ans){
            cout << ans << endl;
            return 0;
        }
        ans += arr[i];
    }
 
    cout << ans << endl;
}