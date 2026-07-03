#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double 
#define endl '\n'

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;

    //primeira linha
    for (int i = 1; i <= n; i++) cout << " ";
    for (int i = 1; i <= n+1; i++) cout << "_";
    cout << endl;

    //n-1 antes da metade
    for (int i = 1; i <= n-1; i++){
        //espacos antes do /
        for (int j = 1; j <= n-i; j++) cout << " ";
        cout << "/";
        for (int j = 1; j <= n+1 + (i-1)*2; j++) cout << " ";
        cout << "\\";
        cout << endl; 
    }

    //metade
    cout << "/";
    for (int i = 1; i <= n; i++)cout << "_";
    for (int i = 1; i <= n*2-1; i++) cout << " ";
    cout << "\\";
    for (int i = 1; i <= n+1; i++)cout << "_";
    cout << endl;

    //n-1 depois da metade
        for (int i = 1; i <= n-1; i++){
        //espacos antes do \   //
        for (int j = 1; j <= i+n; j++) cout << " ";
        cout << "\\";
        for (int j = 1; j <= n+1 + (n-i)*2; j++) cout << " ";
        cout << "/";
        cout << endl; 
    }

    //ultima linha
    for (int i = 1; i <= n*2; i++) cout << " ";
    cout << "\\";
    for (int i = 1; i <= n+1; i++) cout << "_";
    cout << "/";
    cout << endl;
}