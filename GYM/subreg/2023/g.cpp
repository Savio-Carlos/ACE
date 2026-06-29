#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define ld long double
#define endl '\n'

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

struct pt {
    int x, y;

    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator <(const pt p)const{
        if(x!=p.x) return x<p.x;
        return y < p.y;
    }
    friend istream& operator >>(istream& in, pt& p){
        return in >> p.x >> p.y;
    }

    friend ostream& operator <<(ostream& os, pt& p){
        return os << "("<< p.x << " " << p.y << ")" << endl;
    }
};

int orientation(pt a, pt b, pt c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
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
    vector<pt> cv = pontos;
    convex_hull(cv, true);
    // vdebug(cv);
    
    vector<int> ans;
    if (cv.size() == 0){
        for (int i = 1; i <=n; i++) ans.push_back(i);
    }
    else{
        for (auto p : cv)ans.push_back(mp[p]);
    }
    sort(all(ans));
    for(auto u : ans) cout << u << " ";
    cout << endl;
}