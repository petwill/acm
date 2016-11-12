//http://acm.csie.org/ntujudge/contest_view.php?id=2755&contest_id=480
// template PEC
/**
    A dominator tree is a tree where each node's children are those nodes it immediately dominates.
    Because the immediate dominator is unique, it is a tree.
    The start node is the root of the tree.
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct DominatorTree{
#define REP(i,s,e) for(int i=(s);i<=(e);i++)
#define REPD(i,s,e) for(int i=(s);i>=(e);i--)
  int n , m , s;
  vector< int > g[ maxn ] , pred[ maxn ];
  vector< int > cov[ maxn ];
  int dfn[ maxn ] , nfd[ maxn ] , ts;
  int par[ maxn ];
  int sdom[ maxn ] , idom[ maxn ];
  int mom[ maxn ] , mn[ maxn ];

  inline bool cmp( int u , int v )
  { return dfn[ u ] < dfn[ v ]; }

  int eval( int u ){
    if( mom[ u ] == u ) return u;
    int res = eval( mom[ u ] );
    if(cmp( sdom[ mn[ mom[ u ] ] ] , sdom[ mn[ u ] ] ))
      mn[ u ] = mn[ mom[ u ] ];
    return mom[ u ] = res;
  }

  void init( int _n , int _m , int _s ){
    ts = 0; n = _n; m = _m; s = _s;
    REP( i, 1, n ) g[ i ].clear(), pred[ i ].clear();
  }
  void addEdge( int u , int v ){
    g[ u ].push_back( v );
    pred[ v ].push_back( u );
  }
  void dfs( int u ){
    ts++;
    dfn[ u ] = ts;
    nfd[ ts ] = u;
    for( int v : g[ u ] ) if( dfn[ v ] == 0 ){
      par[ v ] = u;
      dfs( v );
    }
  }
  void build(){
    REP( i , 1 , n ){
      dfn[ i ] = nfd[ i ] = 0;
      cov[ i ].clear();
      mom[ i ] = mn[ i ] = sdom[ i ] = i;
    }
    dfs( s );
    REPD( i , n , 2 ){
      int u = nfd[ i ];
      if( u == 0 ) continue ;
      for( int v : pred[ u ] ) if( dfn[ v ] ){
        eval( v );
        if( cmp( sdom[ mn[ v ] ] , sdom[ u ] ) )
          sdom[ u ] = sdom[ mn[ v ] ];
      }
      cov[ sdom[ u ] ].push_back( u );
      mom[ u ] = par[ u ];
      for( int w : cov[ par[ u ] ] ){
        eval( w );
        if( cmp( sdom[ mn[ w ] ] , par[ u ] ) )
          idom[ w ] = mn[ w ];
        else idom[ w ] = par[ u ];
      }
      cov[ par[ u ] ].clear();
    }
    REP( i , 2 , n ){
      int u = nfd[ i ];
      if( u == 0 ) continue ;
      if( idom[ u ] != sdom[ u ] )
        idom[ u ] = idom[ idom[ u ] ];
    }
  }
} domT;

int up[maxn][30];
int timer;
int c[maxn], cmn[maxn];
int tin[maxn], tout[maxn];
vector<int> dom[maxn];

void dfs(int u, int p = 1, int mn = 1e9) {
    cmn[u] = min( mn, c[u] );
    tin[u] = timer ++;
    up[u][0] = p;
    for(int i = 1; i < 23; i++)
        up[u][i] = up[ up[u][i-1] ][ i-1 ];
    for (int v: dom[u])
        dfs(v, u, cmn[u]);
    tout[u] = timer ++;
}
bool upper (int a, int b) {
    return tin [a] <= tin [b] && tout [a] >= tout [b];
}
int lca (int a, int b) {
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i = 22; i >= 0; --i){
        if (! upper (up[a][i], b))
            a = up[a][i];
    }
    return up [a][0];
}
int main() {
    int n,m;cin>>n>>m;
    domT.init(n, m, 1);
    for(int i=0;i<m;i++) {
        int u,v;scanf("%d %d", &u, &v);
        domT.addEdge(u, v);
    }
    domT.build();
    // construct dom tree from idom
    for(int i=2;i<=n;i++) dom[ domT.idom[i] ].push_back(i);
    for(int i=1;i<=n;i++) scanf("%d", &c[i]);
    timer=1;dfs(1);
    int q;cin>>q;
    while(q--) {
        int k;cin>>k;
        int cur; scanf("%d", &cur);
        for(int i = 1; i < k; i++) {
            int x; scanf("%d", &x);
            cur = lca( cur, x);
        }
        cout << cmn[cur] << endl;
    }
}
