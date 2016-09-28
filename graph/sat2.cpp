//https://www.hackerrank.com/contests/world-codesprint-7/challenges/episode-recording/
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())

struct SCC{
    #define maxn 1005
    vector<int> G[maxn];
    stack<int> Stack;
    int scnt, Time;
    int belong[maxn], dfn[maxn], low[maxn], indegree[maxn];
    bool instack[maxn];
    void init(int n) {
        scnt = Time = 0;
        for(int i = 0; i < n; i++) G[i].clear();
        while(!Stack.empty()) Stack.pop();
        memset(indegree, 0, sizeof(indegree));
        memset(dfn, 0, sizeof(dfn));
        memset(instack, false, sizeof(instack));
    }
    void dfs(int u) {
        dfn[u] = low[u] = ++Time;
        Stack.push(u); instack[u] = true;
        for(int v : G[u]) {
            if ( !dfn[v] ) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(instack[v])
                low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]) {
            scnt++;
            int tp;
            do{
                tp = Stack.top(); Stack.pop();
                instack[tp] = false;
                belong[tp] = scnt;
            } while(tp != u);
        }
    }
    void tarjan(int n) {
        //zero based here
        for(int i = 0; i < n; i++)
            if(!dfn[i])
                dfs(i);
    }
};
#define SAT2NODE 2000
/*
1. The nodes need to be split. So change convert() accordingly.
2. Using clauses, populate scc edges.
3. Call possible, to find if a valid solution is possible or not.
4. Dont forget to keep space for !A variables
*/
struct SAT2 {
    SCC scc;

    SAT2(): bfscc(1) {}

    void clear( int n ) {
        scc.init( n );
    }

    int convert ( int n ) { ///Change here. Depends on how input is provided
        return n * 2;
    }

    void mustTrue ( int a ) { ///A is True
        scc.G[a^1].pb ( a );
    }
    void orClause ( int a, int b ) { /// A || B clause
        //!a->b !b->a
        scc.G[a^1].pb ( b );
        scc.G[b^1].pb ( a );
    }
    void xorClause ( int a, int b ) {
        orClause( a, b );
        orClause( a^1, b^1 );
    }
    void andClause ( int a, int b ) {
        scc.G[a].pb ( b );
        scc.G[b].pb ( a );
    }
    void notAndClause ( int a, int b ) {
        scc.G[a].pb ( b ^ 1 );
        scc.G[b].pb ( a ^ 1 );
    }
    #define FOR(i,x,y) for(int i = (x) ; i < (y) ; ++i)
    /// Out of all possible option, only one is true
    void atMostOneClause ( int a[], int n, int flag ) {
        if ( flag == 0 ) { /// At most one can be false
            FOR(i,0,n){
                a[i] = a[i] ^ 1;
            }
        }
        FOR(i,0,n) {
            FOR(j,i+1,n) {
                orClause( a[i] ^ 1, a[j] ^ 1 ); /// !a || !b both being true not allowed
            }
        }
    }

    ///Send n, total number of nodes, after expansion
    bool possible( int n ) {

        scc.tarjan( n );
        for(int i = 1; i < n; i+=2) {
            int a = i, b = i^1;
            ///Falls on same cycle a and !a.
            if ( scc.belong[a] == scc.belong[b] ) return false;
        }
        ///Valid solution exists
        return true;
    }

    ///To determine if A can be true. It cannot be true, if a path exists from A to !A.
    int vis[SAT2NODE], qqq[SAT2NODE], bfscc;
    void bfs( int s ) {
        bfscc++;
        int qs = 0, qt = 0;
        vis[s] = bfscc;
        qqq[qt++] = s;
        while ( qs < qt ) {
            s = qqq[qs++];
            for(int t : scc.G[s] ){
                if ( vis[t] != bfscc ) {
                    vis[t] = bfscc;
                    qqq[qt++] = t;
                }
            }
        }
    }

}sat2;

vector< pair<int,int> > ep;

void buildGraph ( int b, int e ) {

    b = b * 2;
    e = e * 2 + 1;

    for ( int i = b; i <= e; i += 2 ) {
        ///First make sure only one between live and repeat is recorded
        int x = sat2.convert( i );
        int y = sat2.convert( i + 1 );
        sat2.xorClause( x, y );
    }
    for ( int i = b; i <= e; i++ ) {
        for ( int j = i + 1; j <= e; j++ ) {
            ///Check if they overlap
            if ( ep[i].se < ep[j].fi || ep[j].se < ep[i].fi ); ///No overlap
            else {
                int x = sat2.convert( i );
                int y = sat2.convert( j );

                sat2.notAndClause( x, y );
            }
        }
    }
}

void solve () {

        int n; scanf ( "%d", &n );

        ep.clear();
        for(int i = 0; i < n; i++) {
            int a, b, c, d;
            scanf ( "%d %d %d %d", &a, &b, &c, &d );
            ep.pb ( mp(a,b) );
            ep.pb ( mp(c,d) );
        }

        int resL = 0, resR = -1;
        int l = 0, r = -1;

        for ( int r = 0; r < n; r++ ) {
            sat2.clear ( n * 4 );
            buildGraph( l, r );

            while ( !sat2.possible( n * 4 ) ) {
                sat2.clear( n * 4 );
                l++;
                buildGraph ( l, r );
            }

            if ( r - l > resR - resL ) {
                resL = l;
                resR = r;
            }
        }
        printf ( "%d %d\n", resL+1, resR+1 );
}
int main () {
    int t;cin>>t;
    while(t--) solve();
}
