//codeforces Digit Tree
//http://codeforces.com/problemset/problem/715/C
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
const int inf = 0x7fffffff; //beware overflow
const LL INF = 0x7fffffffffffffff; //beware overflow
#define mem(x, y) memset(x, (y), sizeof(x) );
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
     return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s << "[ ";
    for (auto it : c) s << it << " ";
    s << "]";
    return s;
}
template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    o << "{";
    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? "" : ", ") << *it;
    return o << "}";
}
template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->fi << ":" << it->se;
    }
    o << "}";
    return o;
}

typedef long long ll;

bool isprime[100005];
vector<LL> primes;
LL M, PHI;
#define MOD M
ll modpow(ll a, ll b) {
	ll r = 1;
	while(b) {
		if(b&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b >>= 1;
	}
	return r;
}
void Sieve(int n) {
	memset(isprime, 1, sizeof(isprime));
	isprime[1] = false;
	for(int i = 2; i <= n; i++) {
		if(isprime[i]) {
			primes.pb(i);
			for(int j = 2*i; j <= n; j += i)
				isprime[j] = false;
		}
	}
}

LL phi(LL n) {
	ll num = 1; ll num2 = n;
	for(ll i = 0; primes[i]*primes[i] <= n; i++) {
		if(n%primes[i]==0) {
			num2/=primes[i];
			num*=(primes[i]-1);
		}
		while(n%primes[i]==0) {
			n/=primes[i];
		}
	}
	if(n>1) {
		num2/=n; num*=(n-1);
	}
	n = 1;
	num *= num2;
	return num;
}
ll inv(ll a) {
	return modpow(a, PHI-1);
}
#define maxn 100005
struct edge{
    int u, v, dig;
    int no(int x) {
        return x == u ? v : u;
    }
};
vector<edge> e;
vector<int> G[maxn];
LL n,  ans;
bool vis[maxn];
int sz[maxn], dep[maxn];
LL tenPow[maxn];
int dfs(int u, int p, int d) {
    sz[u] = 1;
    dep[u] = d;
    for(int eind : G[u] ) {
        int v = e[eind].no(u);
        if(  v == p || vis[v] ) continue;
        sz[u] += dfs(v, u, d+1);
    }
    return sz[u];
}
int findCenter(int u, int p, int treesize) {
    for(int eind : G[u] ) {
        int v = e[eind].no(u);
        if( v == p || vis[v] ) continue;
        if( sz[v]*2 > treesize)
            return findCenter( v, u, treesize);
    }
    return u;
}

LL up[maxn], down[maxn];
int belong[maxn];
map<LL, LL> tot;
vector< map<LL, LL> > vec;
vector<int> pt;

void calc(int u, int p, int b, int d) {
    pt.pb( u );
    belong[u] = b;
    dep[u] = d;

    int id =  find_if( all(G[u]) ,[u,p](int x) { return e[x].no(u) == p; }) - G[u].begin();
    down[u] = ( down[p]*10 + e[ G[u][id] ].dig )%M;
    up[u] =  (tenPow[ d-1 ]*e[ G[u][id] ].dig + up[p] )%M;

    for(int eind : G[u]) {
        int v = e[eind].no(u);
        if( vis[v] || v == p ) continue;
        calc( v, u, b, d+1);
    }

    vec[b][ up[u] ]++;
    tot[ up[u] ]++;
}

LL solve(int cent) {
    //cent is the root now
    vector<int> L;
    for(int eind : G[cent]) {
        int v = e[eind].no(cent);
        if( !vis[v] ) {
            L.pb( v );
        }
    }
    vec.clear();
    vec.resize( SZ(L), {} );
    tot.clear();
    up[cent] = down[cent] = 0;
    dep[cent] = 0;
    pt.clear();
    for(int i = 0; i < SZ(L); i++)
        calc( L[i], cent, i, 1);

    LL ret = 0;
    for(int u : pt) {
        LL tmp = (-down[u]+M)%M;
        tmp = ( tmp*inv( tenPow[ dep[u] ] ))%M;
        ret += tot[ tmp ] - vec[ belong[u] ][ tmp ];
    }
    assert( (LL)count_if(all(pt), [] (int x) { return up[x] == 0; } ) == tot[0]);
    LL tmp = tot[0] + (LL)count_if(all(pt), [] (int x) { return down[x] == 0; } );
    debug("%lld\n", tmp);
    return ret+tmp;
}
void solveAll(int node) {
    dfs(node, -1, 0);
    int cent = findCenter(node, -1, sz[node]);
    ans += solve( cent );
    debug("%d %lld\n", cent, ans);
    vis[cent] = true;
    for(int eind : G[cent] ) {
        int v = e[eind].no(cent);
        if( vis[v] ) continue;
        solveAll(v);
    }
}
int main() {
    cin>>n>>M;
	Sieve( 100000 );
    PHI = phi(M);
    for(int i = 0; i < n-1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        G[a].pb( SZ(e) ); G[b].pb( SZ(e) );
        e.pb( edge{a, b, c} );
    }
    //init
    tenPow[0] = 1;
    for(int i = 1; i < maxn; i++) tenPow[i] = (tenPow[i-1]*10)%M;
    ans = 0;
    mem( vis, false);
    solveAll(0);
    cout<<ans<<endl;
}
