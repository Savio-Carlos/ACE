#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n = 0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, int x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}

	int pref(int i) { // soma [0, i]
		int ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	int query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
};

signed main(){
    winton;
    int n, b, r, w;
    cin >> n >> b >> r >> w;
    vector<int> pfx(b+1), t(n);
    
    pfx[0] = 0;
    for (int i = 1; i <= b; i++) {
        int x; 
        cin >> x;
        pfx[i] = pfx[i-1] + x;
    }
    for (auto &u : t) cin >> u;

    auto check = [&] (int mid) -> bool{
        Bit bit_dist(b), bit_cnt(b);
        vector<int> cnt_grp(b+1, 0);
        int s = 0, d = 0, gsz = 0, bus = 0;
        vector<int> grp;

        auto reset = [&]() {
            for (int di : grp) {
                bit_cnt.update(di-1, -1);
                cnt_grp[di]--;
                if (cnt_grp[di] == 0) bit_dist.update(di-1, -1);
            }
            grp.clear();
            s = d = gsz = 0;
        };

        auto delta = [&](int di) -> int {
            int e = bit_dist.pref(di-1);
            int r = gsz - bit_cnt.pref(di-2);
            return cnt_grp[di] == 0 ? e + r + 1 : e;
        };

        auto add = [&](int di) {
            s += delta(di);
            d = max(d, di);
            gsz++;
            bit_cnt.update(di-1, 1);
            if (cnt_grp[di] == 0) bit_dist.update(di-1, 1);
            cnt_grp[di]++;
            grp.push_back(di);
        };

        auto fits = [&](int di, int start) -> bool {
            int ns = s + delta(di);
            int nd = max(d, di);
            return start + pfx[nd] + 2*w*ns <= mid;
        };

        for (int i = 0; i < n; i++) {
            int di = t[i];
            int start = bus * r;
            if (fits(di, start)) {
                add(di);
            } 
            else {
                reset();
                bus++;
                start = bus * r;
                if (!fits(di, start)) return false;
                add(di);
            }
        }
        return true;
    };
=
    int l = 0, rr = 1e15;
    int ans = -1;
    while (l <= rr) {
        int mid = l + (rr-l)/2;

        if (check(mid)){
            ans = mid;
            rr = mid - 1;
        } 
        else l = mid + 1;
    }
    cout << ans << endl;
}