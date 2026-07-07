#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end();
#define rall(x) x.rbegin(), x.rend();

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    if(n <= 1){
        cout << 0 << endl;
        return 0;
    }
    //for(int i = 0; i < n; i++) cout << arr[i] << " ";
    //cout << endl;

    int a = arr[0];
    int b = arr[0];
    int c = arr[n-1];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         for(int k = 0; k < n; k++){
    //             cout << arr[i] << " " << arr[j] << " " << arr[k] << " ";
    //             int v = arr[i]*arr[i] + arr[j]*arr[j] + arr[k]*arr[k];
    //             v = v - (arr[i]*arr[j] + arr[i]*arr[k] + arr[k]*arr[j]); 
    //             cout << v << endl;
    //         }
    //     }
    // }
    int v = (a*a + b*b + c*c);
    int k = (a*b + b*c + a*c);
    cout << v - k << endl;
    //cout << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(i == j) continue;
    //         cout << arr[i] << " " << arr[j] << " ";
    //         int v = arr[i]*arr[i] + arr[i]*arr[i] + arr[j]*arr[j];
    //         v = v - (arr[i]*arr[j] + arr[i]*arr[i] + arr[j]*arr[j]);
    //         cout << v << endl;
    //     }
    // }
}