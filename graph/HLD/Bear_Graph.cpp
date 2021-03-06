//http://codeforces.com/problemset/problem/165/D

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
//const int inf = 0x7fffffff; //beware overflow
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


#define maxn 100010
using namespace std;


#define MAXN maxn
struct segment_tree{
    #define right(x) x << 1 | 1
    #define left(x) x << 1
    int* arr;
//    int m[4*MAXN], M[4*MAXN];
    LL sum[4*MAXN];
//    int tag[4*MAXN];
    const int inf = 1e9;

    void pull(int ind) {
        sum[ind] = sum[right(ind)]+sum[left(ind)];
    };

    /// root => 1
    void build(int ind, int l, int r) {

        if( r - l == 1) {
            sum[ind] = 0;
            return;
        }
        int mid = (l+r)>>1;
        build( left(ind), l, mid );
        build( right(ind), mid, r );
        pull(ind);
    }
    LL query_sum(int ind, int L, int R, int ql, int qr) {
        if( L >= qr || R <= ql ) return 0;
        if( R <= qr && L >= ql ) {
            return sum[ind];
        }
        int mid = (L+R)>>1;
        return query_sum(left(ind), L, mid, ql, qr) + query_sum(right(ind), mid, R, ql, qr);
    }
    void modify(int ind, int L, int R, int ql, int qr, int x) {
        if( L >= qr || R <= ql ) return;
        if( R <= qr && L >= ql ) {
            /*
            m[ind] = min(m[ind], x);
            tag[ind] = min(tag[ind], x);
            */
            sum[ind] = x;
            return;
        }
//        push(ind);
        int mid = (L+R)>>1;
        modify(left(ind), L, mid, ql, qr, x);
        modify(right(ind), mid, R, ql, qr, x);
        pull(ind);
    }
}seg;

/**
    template for 樹鍊剖分
    careful => node index [1..n]
    siz[v]表示以v为根的子树的节点总数。
    dep[v]表示v的深度。
    son[v]表示与v在同一重链上的v的儿子节点。
    fa[v]表示v的父亲节点。
    top[v]表示v所在链的顶端节点。
    w[v]表示节点v在线段树中的位置。
    siz[],son[],fa[],dep[]可以在第一遍dfs中求出来，top[]，w[]可在第二遍dfs中求出来。具体过程看代码吧。

    w[root] = 0, max( w[ 1..n ] ) = n-1
    seg_arr[0] won't be queried cause this edge actually doesn't exist
    seg_arr[ 1..n ) is actually used
    every edge in segment tree's index == w[ the deeper node index ]
**/
#define maxm (maxn<<1)
int siz[maxn],top[maxn],son[maxn],dep[maxn],w[maxn],fa[maxn];
int n,m;
struct edge
{
    int to;
    int cost;
    int next;
}e[maxm];
int box[maxn],cnt,tot;
void init()
{
    tot=0;
    son[0]=dep[0]=0;
    memset(box,-1,sizeof(box));
    cnt=0;
}
void add_edge(int from,int to, int cost = 0)
{
    e[cnt].to=to;
    e[cnt].cost = cost;
    e[cnt].next=box[from];
    box[from]=cnt++;
}
void dfs(int now,int pre)
{
    siz[now]=1;
    fa[now]=pre;
    son[now]=0;
    dep[now]=dep[pre]+1;
    int t,v;
    for(t=box[now];t+1;t=e[t].next)
    {
        v=e[t].to;
        if(v!=pre)
        {
            dfs(v,now);
            siz[now]+=siz[v];
            if(siz[son[now]]<siz[v])
            {
                son[now]=v;
            }
        }
    }
}
void dfs2(int now,int tp)
{
    w[now]=tot++;
    top[now]=tp;

    if(son[now])
        dfs2(son[now],top[now]);
    int t,v;
    for(t=box[now];t+1;t=e[t].next)
    {
        v=e[t].to;
//        if( v == fa[now])
//            seg_arr[ w[now] ] = e[t].cost;
        if(v!=fa[now]&&v!=son[now])
            dfs2(v,v);
    }

}

int query(int a,int b) {
    int f1=top[a],f2=top[b],dist=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(a,b);
        }
        dist+=w[a]-w[f1]+1;
        int tmp=seg.query_sum(1,1, n, w[f1],w[a]+1);
        if(tmp)
            return -1;
        a=fa[f1];
        f1=top[a];
    }
    if(a==b)
    return dist;//注意这里
    else
    {
        if(dep[a]>dep[b])
            swap(a,b);
        int tmp=seg.query_sum(1,1, n, w[son[a]],w[b]+1);//注意这里
        if(tmp)
            return -1;
        return dist+w[b]-w[a];
    }
}

void modify(int a, int b, int c) {
    if( top[a] == top[b]) {
        int mn = min( w[a], w[b]);
        int mx = max( w[a], w[b]);
        seg.modify(1, 1, n, mn+1, mx+1, c);
        return;
    }

    if(dep[top[a]] < dep[top[b]])
        swap(a, b);
    seg.modify( 1, 1, n, w[top[a]], w[a] + 1, c);
    modify( fa[top[a]], b, c);
}
/** end template **/

//sometimes needed
int Edge[maxm][2];

int main()
{
    int q,i,a,b;
    scanf("%d",&n);
    init();
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&Edge[i][0],&Edge[i][1]);
        add_edge(Edge[i][0],Edge[i][1]);
        add_edge(Edge[i][1],Edge[i][0]);
    }
    seg.build(1,1,n);
    dfs(1,0);
    dfs2(1,1);
    scanf("%d",&q);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        if(k==3)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
        else
        {
            scanf("%d",&i);
            int tmp;
            if(dep[Edge[i][0]]>dep[Edge[i][1]])
                tmp=Edge[i][0];
            else
                tmp=Edge[i][1];

            if(k==1)
                seg.modify(1, 1, n, w[tmp], w[tmp]+1, 0);
            else
                seg.modify(1, 1, n, w[tmp], w[tmp]+1, 1);
        }
    }
    return 0;
}
