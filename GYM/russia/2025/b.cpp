#include <bits/stdc++.h>
using namespace std;

struct Big {
    vector<uint32_t> d;
    static const uint32_t BASE = 1000000000;
    Big() {}
    Big(uint64_t x) { while (x) { d.push_back(x % BASE); x /= BASE; } }
    Big(const string& s) {
        for (int i = (int)s.size(); i > 0; i -= 9) {
            int l = max(0, i - 9);
            d.push_back((uint32_t)stoul(s.substr(l, i - l)));
        }
        trim();
    }
    void trim() { while (!d.empty() && d.back() == 0) d.pop_back(); }
    bool isZero() const { return d.empty(); }
    int cmp(const Big& o) const {
        if (d.size() != o.d.size()) return d.size() < o.d.size() ? -1 : 1;
        for (int i = (int)d.size() - 1; i >= 0; --i)
            if (d[i] != o.d[i]) return d[i] < o.d[i] ? -1 : 1;
        return 0;
    }
    bool operator<(const Big& o) const { return cmp(o) < 0; }
    bool operator<=(const Big& o) const { return cmp(o) <= 0; }
    bool operator>=(const Big& o) const { return cmp(o) >= 0; }
    bool operator==(const Big& o) const { return cmp(o) == 0; }

    Big operator+(const Big& o) const {
        Big r; r.d.assign(max(d.size(), o.d.size()) + 1, 0);
        uint64_t c = 0;
        for (size_t i = 0; i < r.d.size(); ++i) {
            uint64_t v = c;
            if (i < d.size()) v += d[i];
            if (i < o.d.size()) v += o.d[i];
            r.d[i] = (uint32_t)(v % BASE);
            c = v / BASE;
        }
        r.trim();
        return r;
    }
    Big operator-(const Big& o) const { // assumes *this >= o
        Big r; r.d.assign(d.size(), 0);
        int64_t c = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            int64_t v = (int64_t)d[i] - c - (i < o.d.size() ? (int64_t)o.d[i] : 0);
            if (v < 0) { v += BASE; c = 1; } else c = 0;
            r.d[i] = (uint32_t)v;
        }
        r.trim();
        return r;
    }
    Big mulSmall(uint64_t m) const {
        Big r; r.d.assign(d.size() + 2, 0);
        uint64_t c = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            __uint128_t v = (__uint128_t)d[i] * m + c;
            r.d[i] = (uint32_t)(v % BASE);
            c = (uint64_t)(v / BASE);
        }
        size_t i = d.size();
        while (c) { r.d[i++] = (uint32_t)(c % BASE); c /= BASE; }
        r.trim();
        return r;
    }
    Big operator*(const Big& o) const {
        Big r; r.d.assign(d.size() + o.d.size() + 1, 0);
        for (size_t i = 0; i < d.size(); ++i) {
            uint64_t c = 0;
            for (size_t j = 0; j < o.d.size(); ++j) {
                __uint128_t v = (__uint128_t)d[i] * o.d[j] + r.d[i+j] + c;
                r.d[i+j] = (uint32_t)(v % BASE);
                c = (uint64_t)(v / BASE);
            }
            size_t k = i + o.d.size();
            while (c) { uint64_t v = (uint64_t)r.d[k] + c; r.d[k] = v % BASE; c = v / BASE; ++k; }
        }
        r.trim();
        return r;
    }
    Big divSmall(uint64_t m, uint64_t* rem = nullptr) const {
        Big r; r.d.assign(d.size(), 0);
        uint64_t c = 0;
        for (int i = (int)d.size() - 1; i >= 0; --i) {
            __uint128_t v = (__uint128_t)c * BASE + d[i];
            r.d[i] = (uint32_t)(v / m);
            c = (uint64_t)(v % m);
        }
        if (rem) *rem = c;
        r.trim();
        return r;
    }
    string str() const {
        if (d.empty()) return "0";
        string s = to_string(d.back());
        for (int i = (int)d.size() - 2; i >= 0; --i) {
            string p = to_string(d[i]);
            s += string(9 - p.size(), '0') + p;
        }
        return s;
    }
};

Big scoreOf(const Big& t) {
    if (t.isZero()) return Big(0);
    uint64_t rem;
    Big full = t.divSmall(5, &rem);
    Big s;
    if (!full.isZero()) {
        Big fm1 = full - Big(1);
        s = full.mulSmall(50) * fm1 + full.mulSmall(70);
    }
    Big k20 = full.mulSmall(20);
    Big a = k20 + Big(10);   // tetrises j=0,1,2 in current group
    Big b = k20 + Big(20);   // tetrises j=3,4 in current group
    for (uint64_t j = 0; j < rem; ++j) {
        if (j < 3) s = s + a;
        else       s = s + b;
    }
    return s;
}

int main() {
    string xs;
    cin >> xs;
    if (xs.empty()) xs = "0";
    Big X(xs);
    if (X.isZero()) { cout << "0 0\n"; return 0; }

    Big lo(1), hi(1);
    while (scoreOf(hi) < X) hi = hi.mulSmall(2);
    while (lo < hi) {
        Big mid = (lo + hi).divSmall(2);
        if (scoreOf(mid) >= X) hi = mid;
        else lo = mid + Big(1);
    }
    Big t = lo;
    Big total = scoreOf(t);
    Big level = (t - Big(1)).mulSmall(2).divSmall(5);
    cout << level.str() << " " << total.str() << "\n";
    return 0;
}