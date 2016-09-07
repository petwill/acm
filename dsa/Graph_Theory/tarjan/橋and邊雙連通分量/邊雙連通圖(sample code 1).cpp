//ntu judge  Cactus
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
const LL mod = 1e9+7;
LL pow2[100005];
/** needed for tarjan **/
// bcc is a set of verticles, ä¸å«å‰²é»ž
#define maxn 100005
#define maxm 100005
int n, m;
int dfn[maxn], low[maxn];
stack<int> st;
int Time;
int bcnt;
vector<int> G[maxn];
int id[maxn]; // id in new graph( ç¸®é»ž )
bool in_cyc[maxn];
/** **/

void tarjan(int s, int p){
    dfn[s] = low[s] = ++Time;
    st.push(s);
    for(int to : G[s]) if( to != p ){
        if(!dfn[to]) tarjan(to, s);
        low[s] = min(low[s], low[to]);
    }
    if(low[s] == dfn[s]){
        in_cyc[bcnt] = st.top()!=s;
        while(1){
            int t = st.top();st.pop();
            id[t] = bcnt;
            if(t == s) break;
        }
        bcnt++;
    }
}
void init_tarjan() {
    Time = bcnt = 0;
}
/** needed for binary lift **/
int l;
int tin[maxn], tout[maxn];
int timer;
int up[maxn][20];
vector<int> g[maxn];
/** **/
int  Cnt[maxn];
void dfs (int v, int p , int d) {
    Cnt[v] = Cnt[p] + in_cyc[v];
    tin[v] = ++timer;
    up [v][0] = p;

    for (int i = 1; i <= l; ++ i)
        up [v] [i] = up [up [v] [i-1]] [i-1];
    for (int to : g[v])  if (to != p)
            dfs (to, v, d+1);
    tout [v] = ++ timer;
}

bool upper (int a, int b) {
    return tin [a] <= tin [b] && tout [a] >= tout [b];
}

int lca (int a, int b) {
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i = l; i >= 0; --i){
        if (! upper (up [a] [i], b))
            a = up [a] [i];
    }
    return up [a][0];
}
void init_binary_lift() {
    l = 1;
    while ((1 << l) <= n) ++ l;
    timer = 0;
}
void construct_graph() {

    int as = 0;
    for(int i = 1; i <= n; i++) {
        for(int j : G[i]) {
            int u = id[i], v = id[j];
            if( u <  v) g[u].pb(v), g[v].pb(u), as++;
        }
    }
    assert( as == bcnt-1);
    n = bcnt;
}
int main() {
    pow2[0] = 1;
    for(int i = 1; i < maxn; i++) pow2[i] = (pow2[i-1]<<1)%mod;
    cin >> n >> m;
    init_tarjan();
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].pb(b), G[b].pb(a);
    }
    in_cyc[0] = false;
    tarjan(1, 1);
    construct_graph();
    int k;cin>>k;
    init_binary_lift();
    mem(Cnt, 0);
    dfs(0, 0, 0);
    while(k--) {
        int a, b; scanf("%d %d", &a, &b);
        a = id[a], b = id[b];
        int c = lca(a, b);
        int p = Cnt[a]+Cnt[b]-2*Cnt[c]+in_cyc[c];
        cout<< pow2[ p ] <<endl;
    }
}
