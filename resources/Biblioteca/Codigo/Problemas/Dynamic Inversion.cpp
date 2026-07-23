//Dynamic Inversions

/*
You are given a permutation {1,2,3,. . . ,n}. Remove m of them one by one, and output the number of
inversion pairs before each removal. The number of inversion pairs of an array A is the number of
ordered pairs (i, j) such that i < j and A[i] > A[j].
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


template<class T = int> struct bit2d {
	vector<T> X;
	vector<vector<T>> Y, t;

	int ub(vector<T>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<pair<T, T>> v) {
		for (auto [x, y] : v) X.push_back(x);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](auto a, auto b) {
			return a.second < b.second; });
		for (auto [x, y] : v) for (int i = ub(X, x); i < t.size(); i += i&-i)
			if (!Y[i].size() or Y[i].back() != y) Y[i].push_back(y);

		for (int i = 0; i < t.size(); i++) t[i].resize(Y[i].size() + 1);
	}

	void update(T x, T y, T v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i)
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] += v;
	}

	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans += t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)-query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1);
	}
};

signed main(){
    winton;
    int n, q;
    while(cin >> n >> q){

        vector<int> a(n), pos(n+1);
        vector<pair<int,int>> plano(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]] = i+1;
            plano[i] = {i+1, a[i]};
        }
        
        bit2d bit(plano);
        for (auto [x,y] : plano) bit.update(x,y,1);
        int sum = 0;
        for (auto [x,y] : plano){
            sum += bit.query(x+1, 1, n, y-1);
        } 
        debug(sum);
        
        while(q--){
            // cout << "sum: " ;
            cout << sum << endl;
            
            int y;
            cin >> y;
            int x = pos[y];
            bit.update(x,y,-1);
            sum -= bit.query(1, y+1, x-1, n);
            sum -= bit.query(x+1, 1, n, y-1);
        }       
    }
}