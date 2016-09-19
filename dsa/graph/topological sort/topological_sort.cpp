#include <bits/stdc++.h>
using namespace std;

#define DEBUG

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
const LL  INF = 0x7fffffffffffffff; //beware overflow
const LL mod = 1e9+7;
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

#define MAXN 100005
#define MAXM 100005
int ans[MAXM];
struct edge{
    int from, to, cost;
};
vector<edge> e;
vector<int> G[MAXN];
vector<int> rG[MAXN];
int visit[MAXN];       // 記錄DFS遍歷過的點
int order[MAXN], n,N, m;    // 儲存一個合理的排列順序
int d[MAXN], D[MAXN];;
bool cycle;         // 記錄DFS的過程中是否偵測到環
struct graph{

    void DFS(int s) {
        // back edge，有環。
        if (visit[s] == 1) {cycle = true; return;}
        // forward edge、cross edge。
        if (visit[s] == 2) return;

        visit[s] = 1;
        /*
        for (int t=0; t<n; ++t)
            if (adj[s][t])
                DFS(t);
        */
        for(int v : G[s]) {
            assert( s == e[v].from);
            DFS( e[v].to );
        }
        visit[s] = 2;

        order[N--] = s;     // 記錄合理的排列順序
    }

    void topological_ordering()
    {
        // 初始化
        memset(visit, 0, sizeof(visit));
        cycle = false;


        // 進行DFS
        for (int s=0; s<n; ++s)
            if (!visit[s])
                DFS(s);

        /*
        if (cycle)
            cout << "圖上有環";
        else {
            // 印出一個合理的排列順序
            for (int i=0; i<n; ++i)
                cout << order[i];
            cout<<endl;
        }
        */
    }
}g;
int main(){
    int T;cin>>T;
    while( T-- ) {
        cin>>n>>m;
        N = n-1;
        for(int i = 0;i < n;i ++) G[i].clear(), rG[i].clear();
        e.clear();

        for(int i = 0;i < m; i++)  {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            e.pb( (edge){a,b,c} );

            G[a].pb( (int)e.size()-1 );

            e.pb( (edge){b,a,c} );
            rG[b].pb((int)e.size()-1 );
        }
        g.topological_ordering();
        fill(d, d+n, 1e9);
        d[0] = 0;
        for(int i = 0;i <n; i++) {
            for(int s : G[ order[i] ]) {
                int v = e[s].to;
                assert( e[s].from == order[i] && v<n);
                d[v] = min(d[v], d[order[i]]+e[s].cost);
            }
        }
        fill(D, D+n, 1e9);
        D[n-1] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int s : rG[ order[i] ]) {
                int v = e[s].to;
                D[v] = min(D[v], D[order[i]]+e[s].cost);
            }
        }
        int shortest = d[n-1];
        assert( d[n-1] == D[0]);
        for(int i = 0; i < 2*m; i += 2) {
            if( d[e[i].from] == 1e9 || D[e[i].to] == 1e9) {ans[i>>1] = -1; continue; }
            ans[i/2] = -(shortest-d[e[i].from]-D[e[i].to]-e[i].cost);
        }
        for(int i = 0; i <m;i++) printf("%d%c", ans[i], (i==m-1)?'\n':' ');
    }
    return 0;
}
