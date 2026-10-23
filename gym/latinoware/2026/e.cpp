#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct frac {
    int num, den;
    frac(int num_ = 0, int den_ = 1) : num(num_), den(den_) {
        assert(den != 0);
        if (den < 0) num = -num, den = -den;
        int g = gcd(abs(num), den);
        num /= g, den /= g;
    }

    friend bool operator<(const frac& l, const frac& r) {
        return l.num * r.den < r.num * l.den;
    }

    friend frac operator+(const frac& l, const frac& r) {
        return {l.num * r.den + l.den * r.num, l.den * r.den};
    }
};

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];

    frac ans;

    // Varre de 'from' até 'to' (exclusivo) com passo s, usando uma pilha
    // monotônica para achar o maior elemento anterior j (a[j] >= a[i]).
    auto sweep = [&](int from, int to, int s) {
        stack<int> st;
        for (int i = from; i != to; i += s) {
            while (!st.empty() and a[st.top()] < a[i]) st.pop();
            if (!st.empty()) {
                int j = st.top(), nb = j + s;  // nb: vizinho de j na direção de i
                if (nb != i or a[j] == a[i]) {
                    frac tot = frac(abs(i - j) - 1) + frac(a[i] - a[nb], a[j] - a[nb]);
                    if (ans < tot) ans = tot;
                }
            }
            st.emplace(i);
        }
    };

    sweep(1, n + 1, 1);
    sweep(n, 0, -1);

    cout << ans.num;
    if (ans.den != 1) cout << "/" << ans.den;
    cout << endl;
}
