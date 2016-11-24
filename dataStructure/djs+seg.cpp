// demo ==> undo djs + segtree with offline
// this program doesn't consider the problem of overflowing varaible ans
// http://acm.csie.org/ntujudge/view_code.php?id=108190&contest_id=472

#define maxn 100005
#define maxm 500005
//can be used to solve dynamic connectivity problem
//can be used with segment tree ==> offline
struct DisjointSet {
  // save() is like recursive
  // undo() is like return
  int n, fa[maxn], sz[maxn];
  vector<pair<int*,int>> h;
  vector<int> sp;
  int ans;
  void init(int tn) {
    ans = 0;
    n=tn;
    for (int i=0; i<n; i++) {
      fa[i]=i;
      sz[i]=1;
    }
    sp.clear(); h.clear();
  }
  void assign(int *k, int v) {
    h.pb({k, *k});
    *k=v;
  }
  void save() { sp.pb(SZ(h)); }
  void undo() {
    assert(!sp.empty());
    int last=sp.back(); sp.pop_back();
    while (SZ(h)!=last) {
      auto x=h.back(); h.pop_back();
      *x.fi=x.se;
    }
  }
  int f(int x) {
    while (fa[x]!=x) x=fa[x];
    return x;
  }
  void uni(int x, int y) {
    x=f(x); y=f(y);
    if (x==y) return ;
    if (sz[x]<sz[y]) swap(x, y);
    //nans stands for new answer
    int t = sz[x]+sz[y];
    int nans = ans - (sz[x]*sz[x]-sz[x]) - (sz[y]*sz[y]-sz[y]) + t*t-t;
    assign(&sz[x], sz[x]+sz[y]);
    assign(&fa[y], x);
    assign(&ans, nans);
  }
}djs;

int n, m;
map<int, int> ma[maxn];
vector<pii> seg[4*maxm];
LL ans[maxm];
void add(int ql, int qr, int a, int b, int id=1, int l=0, int r=m) {
    if( qr <= l || ql >= r ) return;
    if( l >= ql && r <= qr ) {
        seg[id].pb( mp(a, b) );
        return ;
    }
    int mid = (l+r)>>1;
    add( ql, qr, a, b, id*2, l, mid);
    add( ql, qr, a, b, id*2+1, mid, r);
}
void dfs(int u=1, int l=0, int r=m) {

    djs.save();
    for(pii v : seg[u] )  djs.uni( v.fi, v.se );

    if( r-l > 1 ) {
        int mid = (l+r)>>1;
        dfs(u*2, l, mid);
        dfs(u*2+1, mid, r);
    }else {
        // do sth here
        ans[l] = djs.ans;
    }

    djs.undo();
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d %d",&a, &b);
        a--, b--; if( b < a ) swap(a, b);

        if( ma[a].count(b) ) {
            add(ma[a][b], i, a, b);
            ma[a].erase(b);
        }else ma[a][b] = i;
    }
    for(int i = 0; i < n; i++) if( !ma[i].empty() ) {
        for(auto p : ma[i])
            add( p.se, m, i, p.fi);
    }
    djs.init(n);
    dfs();
    for(int i =0; i < m;i++) printf("%lld\n", ans[i]);
}
