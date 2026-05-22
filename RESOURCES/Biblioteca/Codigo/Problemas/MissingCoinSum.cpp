//MissingCoinSUM
 
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