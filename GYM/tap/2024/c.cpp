
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    constexpr const char* RESET      = "\033[0m";
    constexpr const char* BOLD_BLUE  = "\033[1;34m";
    constexpr const char* YELLOW     = "\033[33m";
    constexpr const char* BOLD_WHITE = "\033[1;37m";

    template<typename T, typename = void> struct is_container : false_type {};
    template<typename T> struct is_container<T, void_t<typename T::value_type>> : bool_constant<!is_same_v<T, string> && !is_same_v<T, string_view>> {};

    inline ostream& print_atom(ostream& os, bool b)         { return os << (b ? "true" : "false"); }
    inline ostream& print_atom(ostream& os, char c)         { return os << '\'' << c << '\''; }
    inline ostream& print_atom(ostream& os, const string& s){ return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, string_view s)  { return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, const char* s)  { return os << '"' << s << '"'; }

    template<typename T, enable_if_t<!is_container<T>::value, int> = 0>
    ostream& print_atom(ostream& os, const T& x) { return os << x; }

    template<typename T1, typename T2>
    ostream& print_atom(ostream& os, const pair<T1, T2>& p) {
        os << '{'; print_atom(os, p.first); os << ", "; print_atom(os, p.second); return os << '}';
    }
    template<typename... T>
    ostream& print_atom(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((print_atom(os, args), os << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
        return os << '}';
    }

    template<typename T, typename C>
    ostream& print_atom(ostream& os, stack<T, C> s) {
        os << '{'; bool f = true; while (!s.empty()) { if (!f) os << ", "; print_atom(os, s.top()); s.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C>
    ostream& print_atom(ostream& os, queue<T, C> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.front()); q.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C, typename Cmp>
    ostream& print_atom(ostream& os, priority_queue<T, C, Cmp> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.top()); q.pop(); f = false; } return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& print_atom(ostream& os, const C& v) {
        os << '{'; bool f = true;
        for (const auto& x : v) { if (!f) os << ", "; print_atom(os, x); f = false; }
        return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& operator<<(ostream& os, const C& v)            { return print_atom(os, v); }
    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return print_atom(os, p); }
    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t)  { return print_atom(os, t); }

    inline size_t split_arg(string_view s) {
        int depth = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '"' || c == '\'') {
                char q = c; ++i;
                while (i < s.size() && s[i] != q) { if (s[i] == '\\' && i + 1 < s.size()) ++i; ++i; }
            } else if (c == '(' || c == '[' || c == '{' || c == '<') ++depth;
            else if (c == ')' || c == ']' || c == '}' || c == '>') --depth;
            else if (c == ',' && depth == 0) return i;
        }
        return string_view::npos;
    }

    inline void debug_out(string_view) { cerr << '\n' << flush; }
    template<typename H, typename... T>
    void debug_out(string_view s, const H& h, const T&... t) {
        size_t cpos = split_arg(s);
        auto name = s.substr(0, cpos);
        while (!name.empty() && (name.front() == ' ' || name.front() == '\t')) name.remove_prefix(1);
        while (!name.empty() && (name.back()  == ' ' || name.back()  == '\t')) name.remove_suffix(1);
        cerr << YELLOW << name << RESET << " = " << BOLD_WHITE;
        print_atom(cerr, h) << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            debug_out(cpos == string_view::npos ? string_view{} : s.substr(cpos + 1), t...);
        } 
        else cerr << '\n' << flush;
    }
}
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) do { cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "] " << RESET; dbg::debug_out(#__VA_ARGS__, __VA_ARGS__); } while (0)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) ((void)0)
#endif
 
struct pt { // ponto
    int x, y, z;
    pt(int x_ = 0, int y_ = 0, int z_ = 0) : x(x_), y(y_), z(z_) {}

    pt operator + (const pt p) const { return pt(x+p.x, y+p.y, z+p.z); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y, z-p.z); }
    pt operator * (const int c) const { return pt(x*c  , y*c  , z*c  ); }
    pt operator / (const int c) const { return pt(x/c  , y/c  , z/c  ); }
    int operator * (const pt p) const { return x*p.x + y*p.y + z*p.z; }//dot |
    pt operator ^ (const pt p) const { return pt(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }//cross *
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y >> p.z;
    }
};

struct plane { // plano
    array<pt, 3> p;  // pontos que definem o plano
    array<int, 4> eq; // equacao do plano
    pt dir; //vetor norm(perpendicular ao plano)
    int d; //offset do plano
    plane() {}
    plane(pt p_, pt q_, pt r_) : p({p_, q_, r_}) { build(); }

    friend istream& operator >> (istream& in, plane& P) {
        in >> P.p[0] >> P.p[1] >> P.p[2];
        P.build();
        return in;
    }
    void build() {
        dir = (p[1] - p[0]) ^ (p[2] - p[0]);
        d = dir * p[0];
        eq = {dir.x, dir.y, dir.z, dir*p[0]*(-1)};
    }
};

int side(pt p, plane pl) {
    return (pl.dir * p) - pl.d;
}

signed main(){
    winton;
    int n;
    cin >> n;
    pt apex, sun;
    cin >> apex >> sun;
    vector<pt> pol(n);
    for (auto &[x,y,z] : pol) cin >> x >> y, z = 0;

    for (int i = 0; i < n; i++){
        plane pl(pol[i], pol[(i+1) % n], apex);
        if (side(sun, pl) > 0){
            cout << "S" << endl;
            return 0;   
        } 
    }
    cout << "N" << endl;
}