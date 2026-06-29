#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

struct pt {
    int x, y;
    pt (int x_ = 0, int y_=0) : x(x_), y(y_){}
    bool operator <(const pt p)const{
        if(x!=p.x) return x<p.x;
        return y < p.y;
    }

    bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}

    pt operator +(const pt p)const{return pt(x+p.x, y+p.y);}
    pt operator -(const pt p)const{return pt(x-p.x, y-p.y);}
    pt operator *(const int c)const{return pt(x*c, y*c);}
    int operator *(const pt p)const{return x*p.x + y*p.y;}
    int operator ^(const pt p)const{return x*p.y - y*p.x;}

    friend istream& operator >>(istream& in, pt& p){
        return in >> p.x >> p.y;
    }

    friend ostream& operator <<(ostream& os, pt& p){
        return os << "("<< p.x << " " << p.y << ")" << endl;
    }
};

int sarea2(pt p, pt q, pt r){
    return(q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r){
    return sarea2(p,q,r) >= 0;
}

vector<pt> convex(vector<pt> v){
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    if(v.size() <= 1) return v;
    vector<pt> l, u;
    for(int i = 0; i < v.size(); i++){
        while(l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i])){
            l.pop_back();
        }
        l.push_back(v[i]);
    }
    for(int i = v.size() - 1; i >= 0; i--){
        while(u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i])){
            u.pop_back();
        }
        u.push_back(v[i]);
    }
    l.pop_back();
    u.pop_back();
    for(pt i : u) l.push_back(i);
    return l;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    map<pt, int> mp;
    vector<pt> pontos(n);
    for (int i = 0; i < n; i++){
        cin >> pontos[i];
        mp[pontos[i]] = i+1;
    }
    auto cv = convex(pontos);
    // vdebug(cv);
    vector<int> ans;
    for (auto p : cv)ans.push_back(mp[p]);
    sort(all(ans));
    // ans.erase(unique(all(ans)), ans.end());
    for(auto u : ans) cout << u << " ";
}