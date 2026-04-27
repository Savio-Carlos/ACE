#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

bool eq (ld a, ld b){
    return fabs(a - b) <= eps;
}

struct point {
    ld x, y;
    point(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    bool operator < (const point p) const {
    if (!eq(x, p.x)) return x < p.x;
    if (!eq(y, p.y)) return y < p.y;
    return 0;
	}
	bool operator == (const point p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	point operator + (const point p) const { return point(x+p.x, y+p.y); }
	point operator - (const point p) const { return point(x-p.x, y-p.y); }
	point operator * (const ld c) const { return point(x*c  , y*c  ); }
	point operator / (const ld c) const { return point(x/c  , y/c  ); }
	ld operator * (const point p) const { return x*p.x + y*p.y; }
	ld operator ^ (const point p) const { return x*p.y - y*p.x; }
    friend istream& operator >> (istream& in, point& p) { 
        return in >> p.x >> p.y;
    }

    friend ostream& operator << (ostream& out, point& p) { 
        return out << p.x << " " << p.y;
    }
};

struct line { // reta
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ld dist (point p, point q){
    return hypot(p.y - q.y, p.x - q.x);
}

point rotate90(point p){
    return point(-p.y, p.x);
}

vector<point> circ_line_inter(point a, point b, point c, ld r) { // intersecao da circunf (c, r) e reta ab
	vector<point> ret;
	b = b-a, a = a-c;
	ld A = b*b;
	ld B = a*b;
	ld C = a*a - r*r;
	ld D = B*B - A*C;
	if (D < -eps) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
	if (D > eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
	return ret;
}

vector<point> circ_inter(point a, point b, ld r, ld R) { // intersecao da circunf (a, r) e (b, R)
	vector<point> ret;
	ld d = dist(a, b);
	if (d > r+R or d+min(r, R) < max(r, R)) return ret;
	ld x = (d*d-R*R+r*r)/(2*d);
	ld y = sqrt(r*r-x*x);
	point v = (b-a)/d;
	ret.push_back(a+v*x + rotate90(v)*y);
	if (y > 0) ret.push_back(a+v*x - rotate90(v)*y);
	return ret;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    point st;
    cin >> st;
    vector<pair<point, int>> pts(n);
    for (auto &[u, r] : pts) cin >> u >> r;
    cout << fixed << setprecision(20);

    ld ans = DINF;

    bool inside = true;
    for (int j = 0; j < n; j++){
        auto [ponto2, raio2] = pts[j];
        if (dist(st, ponto2) - eps > raio2) inside = false;
        
    }

    if (inside){
        cout << 0.0 << endl;
        return 0;
    }
    

    for (int i = 0; i < n; i++){
        auto [ponto, raio] = pts[i];
        line t(st, ponto);
        auto inter = circ_line_inter(t.p, t.q, ponto, raio);
        if (inter.empty()) continue;
        point intersecao = inter[0];
        point interseca2 = inter[1];

        // cout << intersecao << endl;
        // cout << interseca2 << endl;

        bool pos = true;
        bool pos2 = true;
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            auto [ponto2, raio2] = pts[j];
            if (dist(intersecao, ponto2) - eps > raio2) pos = false;
            if (inter.size() > 1 && dist(interseca2, ponto2) - eps > raio2) pos2 = false;
        }

        if (pos){
            ans = min(ans, dist(st, intersecao));
        }
        if (pos2){
            ans = min(ans, dist(st, interseca2));
        }
    }

    vector<point> teste;

    for (int i = 0; i < n - 1; i++){
        auto [pt1, r1] = pts[i];
        for (int j = i + 1; j < n; j++){
            auto [pt2, r2] = pts[j];
            auto inter = circ_inter(pt1,pt2,r1,r2);
            
            for (auto u : inter){
                teste.push_back(u);
            } 
        }
    }
    sort(all(teste));
    teste.erase(unique(all(teste)), teste.end());

    for (int i = 0; i < teste.size(); i++){
        auto ponto1 = teste[i];
        bool pos = true;
        for (int j = 0; j < n; j++){
            auto [ponto2, raio2] = pts[j];
            if (dist(ponto1, ponto2) - eps > raio2) {
                pos = false;
                break;
            }
        }
        if (pos){
            ans = min(ans, dist(st, ponto1));
        }
    }

    cout << ans << endl;
}