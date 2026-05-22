//Graph Paths I

// Minimum path length that visits k vertices
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> con(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        con[a][b] = min(c, con[a][b]);
    }
    matrix mt(con);
    mt = mt^k; 
    int ans = mt[0][n-1];
    if (ans == INF) cout << "-1" << endl;
    else cout << ans << endl;

}