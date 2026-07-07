//Graph Paths I
//count number of paths of size K
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> con(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        con[--a][--b]++;
    }
    matrix mt(con);
    
    mt = mt^k;
    cout << mt[0][n-1] << endl;
}