#define maxn 100005
struct segment_tree{
    #define right(x) x << 1 | 1
    #define left(x) x << 1
    int* arr;
    int m[4*maxn];
    int tag[4*maxn];
    const int inf = 1e9;

    void init() {
        //memset(tag, -1, sizeof(tag));
        fill(tag, tag+4*maxn, inf);
    }
    void pull(int ind) {
            m[ind] = min(m[right(ind)] ,m[left(ind)]);
    };
    void push(int ind) {
        if(tag[ind] != inf) {
            tag[left(ind)] = min(tag[left(ind)], tag[ind]);
            tag[right(ind)] = min(tag[right(ind)], tag[ind]);
            m[left(ind)] = min( m[left(ind)], tag[left(ind)]);
            m[right(ind)] = min( m[right(ind)], tag[right(ind)]);
            tag[ind] = inf;
        }
    }
    /// root => 1
    void build(int ind, int l, int r) {

        if( r - l == 1) {
            m[ind] =  arr[l];
            return;
        }
        int mid = (l+r)>>1;
        build( left(ind), l, mid );
        build( right(ind), mid, r );
        pull(ind);
    }
    int query_min(int ind, int L, int R, int ql, int qr) {
        if( L >= qr || R <= ql ) return 1e9;
        if( R <= qr && L >= ql ) {
            return m[ind];
        }
        push(ind);
        int mid = (L+R)>>1;
        return min( query_min(left(ind), L, mid, ql, qr), query_min(right(ind), mid, R, ql, qr));
    }
    void modify(int ind, int L, int R, int ql, int qr, int x) {
        if( L >= qr || R <= ql ) return;
        if( R <= qr && L >= ql ) {

            m[ind] = min(m[ind], x);
            tag[ind] = min(tag[ind], x);

            return;
        }
        push(ind);
        int mid = (L+R)>>1;
        modify(left(ind), L, mid, ql, qr, x);
        modify(right(ind), mid, R, ql, qr, x);
        pull(ind);
    }
};

int seg_arr[maxn];
struct Tree{
    segment_tree seg;
    int n;
    struct Edge { int u, v, c; };
    vector<Edge> e;
    void addEdge(int x, int y, int c) {
        G[x].pb( SZ(e) );
        G[y].pb( SZ(e) );
        e.pb( Edge{x, y, c}  );
    }
    int siz[maxn],max_son[maxn],pa[maxn],dep[maxn];
    /*size of subtree、index of max_son, parent index、depth*/
    int link_top[maxn],link[maxn],timer;
    /*chain top、index in segtree、time stamp*/
    std::vector<int >G[maxn];
    void init(int N) {
        n = N;
        e.clear();
        for(int i = 1; i <= n; i++) G[i].clear();
        timer=0;
        pa[1] = 1;
        dep[1] = 0;
    }
    void find_max_son(int x){
        siz[x]=1;
        max_son[x]=-1;
        for(int e_ind : G[x]) {
            int v = e[e_ind].u == x ? e[e_ind].v : e[e_ind].u ;
            if( v == pa[x] )continue;
            pa[v] = x; dep[v] = dep[x] + 1;
            find_max_son(v);
            if(max_son[x] == -1 || siz[v] > siz[max_son[x]])
                max_son[x] = v;
            siz[x] += siz[v];
        }
    }
    void build_link(int x,int top){
        link[x] = timer++;/*記錄x點的時間戳*/
        link_top[x] = top;
        if(max_son[x] != -1)
            build_link( max_son[x], top);/*優先走訪最大孩子*/

        for(int e_ind : G[x]) {
            int v = e[e_ind].u == x ? e[e_ind].v : e[e_ind].u ;

            if( v == pa[x] ) {
                seg_arr[ link[x] ] = e[e_ind].c;
            }
            if( v == max_son[x] || v == pa[x] )continue;
            // edge from x => v
            build_link(v, v);
        }
    }
    inline int lca(int a,int b){
        /*求LCA，可以在過程中對區間進行處理*/
        int ta=link_top[a],tb=link_top[b];
        while(ta != tb){
            if(dep[ta]<dep[tb]){
                std::swap(ta,tb);
                std::swap(a,b);
            }
            //interval [ link[ta], link[a] ]
            a = pa[ta];
            ta = link_top[a];
        }
        return dep[a] < dep[b] ? a:b;
    }
    
    int modify(int a,int b, int c){
        //modify path a to b
        int ta=link_top[a], tb=link_top[b];
        while(ta != tb){
            if(dep[ta]<dep[tb]){
                std::swap(ta,tb);
                std::swap(a,b);
            }
            //interval [ link[ta],link[a] ]
            //same interval if operate on edges
            seg.modify(1, 1, n, link[ta], link[a]+1, c);
            a = pa[ta];
            ta = link_top[a];
        }
        //a, b are on the same chain
        if( a == b ) ; // interval [ link[a], link[a] ], if operate on edges => no edge
        else {
            if(dep[a]>dep[b])
                swap(a,b);
            //interval [ link[a],link[b] ]
            // if operate on edges ==> [ link[ max_son[a] ], link[b] ]
            seg.modify(1, 1, n, link[ max_son[a] ], link[b]+1, c);
        }
    }
    /* recursive version of modify
    void modify(int a, int b, int c) {
        if( a==b ) return;
        if( link_top[a] == link_top[b]) {
            if( dep[a] > dep[b] ) swap(a, b);
            seg.modify(1, 1, n, link[a]+1, link[b]+1, c);
            assert( link[a]+1 == link[ max_son[a]] );
            return;
        }
        if(dep[link_top[a]] < dep[link_top[b]])
            swap(a, b);
        // a is the node with deeper link_top
        seg.modify( 1, 1, n, link[link_top[a]], link[a] + 1, c);
        modify( pa[link_top[a]], b, c);
    }
    */

    /// Heavy Light Decomposition
    void HLD() {
        // root is indexed 1 here !
        find_max_son(1);
        build_link(1, 1);
    }
}tree;
