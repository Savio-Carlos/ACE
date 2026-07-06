// SegTree Ultimate (Lazy Propagation, generica)
// =============================================================================
// Ideia: o MOTOR (struct SegTree<Node,Tag>) nunca muda. Voce so troca os dois
// structs pequenos Node/Tag pra escolher a operacao (soma/min/max/assign/etc).
// Toda a "operacao" fica no operator+ do Node e no apply()/compose do Tag.
//
// Contratos que Node e Tag precisam cumprir:
//   Node():             elemento neutro da query (identidade do merge)
//   Node(x):            folha com valor x (len = 1)
//   Node operator+:     merge de dois nodes  (tem que ser associativo)
//   Node::apply(Tag,?): aplica uma atualizacao ao node (usa node.len)
//   Tag():              atualizacao "vazia" (no-op)
//   Tag::apply(Tag):    compoe: this recebe outra tag por cima
//   Tag::empty():       true se a tag e no-op (pra nao propagar a toa)
//
// Presets prontos no fim do arquivo (soma+add, max+add, min+assign, MOD...).
//
// Complexidades: build O(n), query/update O(log n), find_first O(log n)
//
// API:
//   SegTree<Node,Tag> st(n);              // n folhas neutras
//   SegTree<Node,Tag> st(vector<T>);      // build a partir de vetor
//   st.update(l, r, Tag{...});            // atualiza range [l,r] (0-indexado)
//   st.query(l, r).sum;                   // consulta range [l,r]
//   st.pointSet(i, Node(x));              // seta a folha i
//   st.find_first(l, r, pred);            // busca binaria na arvore (ver abaixo)
// =============================================================================

typedef long long ll;

template<typename Node, typename Tag>
struct SegTree {
    int n;
    vector<Node> tree;
    vector<Tag>  lazy;

    SegTree() : n(0) {}
    SegTree(int n) { assign(n); }
    template<typename U> SegTree(const vector<U>& v) { build(v); }

    void assign(int n_) {                    // n folhas neutras (Node())
        n = n_;
        tree.assign(4*n, Node());
        lazy.assign(4*n, Tag());
    }
    template<typename U> void build(const vector<U>& v) {
        n = v.size();
        tree.assign(4*n, Node());
        lazy.assign(4*n, Tag());
        if (n) build(v, 1, 0, n-1);
    }

    void applyTo(int node, const Tag& t) {   // aplica t no node e acumula no lazy
        tree[node].apply(t);
        lazy[node].apply(t);
    }
    void push(int node) {                    // empurra lazy pros filhos
        if (!lazy[node].empty()) {
            applyTo(2*node, lazy[node]);
            applyTo(2*node+1, lazy[node]);
            lazy[node] = Tag();
        }
    }

    template<typename U>
    void build(const vector<U>& v, int node, int l, int r) {
        if (l == r) { tree[node] = Node(v[l]); return; }
        int m = (l+r)/2;
        build(v, 2*node, l, m);
        build(v, 2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int ql, int qr, const Tag& t) { if (n) update(1,0,n-1,ql,qr,t); }
    void update(int node, int l, int r, int ql, int qr, const Tag& t) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { applyTo(node, t); return; }
        push(node);
        int m = (l+r)/2;
        update(2*node, l, m, ql, qr, t);
        update(2*node+1, m+1, r, ql, qr, t);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    Node query(int ql, int qr) { return n ? query(1,0,n-1,ql,qr) : Node(); }
    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node();
        if (ql <= l && r <= qr) return tree[node];
        push(node);
        int m = (l+r)/2;
        return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
    }

    void pointSet(int i, const Node& val) { pointSet(1,0,n-1,i,val); }
    void pointSet(int node, int l, int r, int i, const Node& val) {
        if (l == r) { tree[node] = val; return; }
        push(node);
        int m = (l+r)/2;
        if (i <= m) pointSet(2*node, l, m, i, val);
        else        pointSet(2*node+1, m+1, r, i, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // Busca binaria na arvore.
    // Retorna o MENOR indice i em [ql,qr] tal que pred( merge de [ql..i] ) == true.
    // pred tem que ser monotono nos prefixos (false...false,true...true). -1 se nunca.
    // Ex: menor prefixo com soma >= x  ->  find_first(0,n-1,[&](const Node&nd){return nd.sum>=x;})
    template<typename F> int find_first(int ql, int qr, const F& pred) {
        Node acc = Node();
        return find_first(1, 0, n-1, ql, qr, pred, acc);
    }
    template<typename F>
    int find_first(int node, int l, int r, int ql, int qr, const F& pred, Node& acc) {
        if (qr < l || r < ql) return -1;
        if (ql <= l && r <= qr) {
            Node cand = acc + tree[node];
            if (!pred(cand)) { acc = cand; return -1; }
            while (l < r) {                  // achou no bloco: desce pra folha
                push(node);
                int m = (l+r)/2;
                Node left = acc + tree[2*node];
                if (pred(left)) { node = 2*node;   r = m; }
                else            { acc = left; node = 2*node+1; l = m+1; }
            }
            return l;
        }
        push(node);
        int m = (l+r)/2;
        int res = find_first(2*node, l, m, ql, qr, pred, acc);
        if (res != -1) return res;
        return find_first(2*node+1, m+1, r, ql, qr, pred, acc);
    }
};

// =============================================================================
// mint : inteiro modular com operator overloading (o "% MOD" plugavel)
// Use como valor dentro do Node (ex: Node com mint sum). Divisao usa Fermat,
// entao MOD tem que ser primo.
// =============================================================================
const ll MOD = 1e9 + 7;
struct mint {
    ll v;
    mint(ll x = 0) { v = x % MOD; if (v < 0) v += MOD; }
    mint& operator+=(const mint& o){ v += o.v; if (v >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& o){ v -= o.v; if (v < 0)   v += MOD; return *this; }
    mint& operator*=(const mint& o){ v = v * o.v % MOD; return *this; }
    mint pow(ll e) const { mint r = 1, b = *this; while (e) { if (e&1) r *= b; b *= b; e >>= 1; } return r; }
    mint inv() const { return pow(MOD - 2); }
    mint& operator/=(const mint& o){ return *this *= o.inv(); }
    friend mint operator+(mint a, const mint& b){ return a += b; }
    friend mint operator-(mint a, const mint& b){ return a -= b; }
    friend mint operator*(mint a, const mint& b){ return a *= b; }
    friend mint operator/(mint a, const mint& b){ return a /= b; }
    friend bool operator==(const mint& a, const mint& b){ return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b){ return a.v != b.v; }
    friend ostream& operator<<(ostream& os, const mint& m){ return os << m.v; }
};

// =============================================================================
// Compressor : compressao de coordenadas reutilizavel
//   Compressor<int> C;
//   for (x : entrada) C.add(x);
//   C.build();
//   int id = C.idx(x);          // id comprimido 0..C.size()-1
//   int tam = C.size();         // tamanho pra criar a SegTree
//   int orig = C.val(id);       // volta pro valor original
// =============================================================================
template<typename T>
struct Compressor {
    vector<T> vals;
    void add(T x) { vals.push_back(x); }
    void build() {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }
    int size() const { return (int)vals.size(); }
    int idx(T x) const { return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()); }
    T   val(int i) const { return vals[i]; }
};

// =============================================================================
// ===============================  PRESETS  ===================================
// Copie UM bloco Node/Tag pra cima do "struct SegTree" e use SegTree<Node,Tag>.
// Node guarda 'len' (tamanho do range) => funciona com ranges nao uniformes,
// como os que aparecem depois de compressao de coordenada.
// =============================================================================
/*
// ---- (1) SOMA de range + ADD em range ----  st.query(l,r).sum
struct Tag {
    ll add = 0;
    void apply(const Tag& t){ add += t.add; }
    bool empty() const { return add == 0; }
};
struct Node {
    ll sum = 0; int len = 0;
    Node() {}
    Node(ll x): sum(x), len(1) {}
    void apply(const Tag& t){ sum += t.add * len; }
    friend Node operator+(const Node& a, const Node& b){
        Node r; r.sum = a.sum + b.sum; r.len = a.len + b.len; return r;
    }
};

// ---- (2) MAX de range + ADD em range ----  st.query(l,r).mx
struct Tag {
    ll add = 0;
    void apply(const Tag& t){ add += t.add; }
    bool empty() const { return add == 0; }
};
struct Node {
    ll mx = LLONG_MIN; int len = 0;
    Node() {}
    Node(ll x): mx(x), len(1) {}
    void apply(const Tag& t){ mx += t.add; }
    friend Node operator+(const Node& a, const Node& b){
        Node r; r.mx = max(a.mx, b.mx); r.len = a.len + b.len; return r;
    }
};

// ---- (3) MIN de range + ASSIGN em range ----  st.query(l,r).mn
struct Tag {
    ll val = 0; bool set = false;
    void apply(const Tag& t){ if (t.set) { val = t.val; set = true; } }
    bool empty() const { return !set; }
};
struct Node {
    ll mn = LLONG_MAX; int len = 0;
    Node() {}
    Node(ll x): mn(x), len(1) {}
    void apply(const Tag& t){ if (t.set) mn = t.val; }
    friend Node operator+(const Node& a, const Node& b){
        Node r; r.mn = min(a.mn, b.mn); r.len = a.len + b.len; return r;
    }
};
// atualizar: st.update(l, r, Tag{x, true});

// ---- (4) SOMA + ADD com MOD (usa mint) ----  st.query(l,r).sum
struct Tag {
    mint add = 0;
    void apply(const Tag& t){ add += t.add; }
    bool empty() const { return add == mint(0); }
};
struct Node {
    mint sum = 0; int len = 0;
    Node() {}
    Node(mint x): sum(x), len(1) {}
    void apply(const Tag& t){ sum += t.add * mint(len); }
    friend Node operator+(const Node& a, const Node& b){
        Node r; r.sum = a.sum + b.sum; r.len = a.len + b.len; return r;
    }
};

// ---- (5) SOMA + ASSIGN em range ----  st.query(l,r).sum ; update: Tag{x,true}
struct Tag {
    ll val = 0; bool set = false;
    void apply(const Tag& t){ if (t.set) { val = t.val; set = true; } }
    bool empty() const { return !set; }
};
struct Node {
    ll sum = 0; int len = 0;
    Node() {}
    Node(ll x): sum(x), len(1) {}
    void apply(const Tag& t){ if (t.set) sum = t.val * len; }
    friend Node operator+(const Node& a, const Node& b){
        Node r; r.sum = a.sum + b.sum; r.len = a.len + b.len; return r;
    }
};
*/
