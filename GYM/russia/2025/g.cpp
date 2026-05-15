    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define ld long double
    #define all(x) x.begin(), x.end();
    #define rall(x) x.rbegin(), x.rend();
    #define endl '\n'
    #define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

    signed main(){
        fastio;
        int n, k;
        cin >> n >> k;
        vector<int> original(n);
        for (int i = 0; i < n; i++) original[i] = i;
        auto cur = original;


        vector<int> nxt;
        for (int kk = 0; kk < k; kk++){
            vector<int> temp;
            for (int i = kk; i < n; i+=k){
                // cout << i << " idx\n";
                temp.push_back(cur[i]);
            }
            for (int j = temp.size() - 1; j >= 0; j--) nxt.push_back(temp[j]);
        }

        vector<int> graph(n);
        vector<int> from(n);
        for (int i = 0; i < n; i++){
            graph[nxt[i]] = i;
        }
        int ans = 1;
        for (int i = 0; i < n; i++){
            int cur = i;
            int cnt = 1;
            // cout << "i: " << i << " ";
            while(graph[cur] != i){
                cur = graph[cur];
                // cout << "" << cur << " ";
                cnt++;
            } 
            // cout << endl;
            ans = lcm(ans,cnt);
        }
        cout << ans << endl;
    }