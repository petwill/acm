// this HLD operate on nodes
#define maxn 200005
struct segment_tree{
    #define right(x) x << 1 | 1
    #define left(x) x << 1
    int sum[4*maxn];
    int tag[4*maxn];

    void init() {
        mem(sum, 0);
        mem(tag, 0);
    }
    void pull(int ind) {
            sum[ind] = (sum[right(ind)] +sum[left(ind)]);
    };
    void push(int ind) {
        if( tag[ind] ) {
            tag[left(ind)] +=  tag[ind];
            tag[right(ind)] += tag[ind];
            sum[left(ind)] += tag[ind];
            sum[right(ind)] +=  tag[ind];
            tag[ind] = 0;
        }
    }
    int query(int ind, int L, int R, int ql, int qr) {
        if( L >= qr || R <= ql ) return 0;
        if( R <= qr && L >= ql ) {
            return sum[ind];
        }
        push(ind);
        int mid = (L+R)>>1;
        return ( query(left(ind), L, mid, ql, qr)+ query(right(ind), mid, R, ql, qr));
    }
    void modify(int ind, int L, int R, int ql, int qr, int x) {
        if( L >= qr || R <= ql ) return;
        if( R <= qr && L >= ql ) {
            tag[ind] +=  x;
            sum[ind] += x;
            return;
        }
        push(ind);
        int mid = (L+R)>>1;
        modify(left(ind), L, mid, ql, qr, x);
        modify(right(ind), mid, R, ql, qr, x);
        pull(ind);
    }
};
struct Tree{
    segment_tree seg;
    int n;
    std::vector<int> G[maxn];
    void addEdge(int x, int y, int c=0) {
        G[x].pb(y);
        G[y].pb(x);
    }
    int siz[maxn],max_son[maxn],pa[maxn],dep[maxn];
    /*size of subtree、index of max_son, parent index、depth*/
    int link_top[maxn],link[maxn],timer;
    /*chain top、index in segtree、time stamp*/
    void init(int N) {
        seg.init();
        n = N;
        for(int i = 0; i < n; i++) G[i].clear();
        timer=0; pa[0] = 0; dep[0] = 0;
    }
    void find_max_son(int x){
        siz[x]=1;
        max_son[x]=-1;
        for(int v : G[x]) {
            if( v == pa[x] )continue;
            pa[v] = x; dep[v] = dep[x] + 1;
            find_max_son(v);
            if(max_son[x] == -1 || siz[v] > siz[max_son[x]])
                max_son[x] = v;
            siz[x] += siz[v];
        }
    }
    void build_link(int x,int top){
        //be careful, timer affects the starting index of the segment tree
        link[x] = timer++;/*記錄x點的時間戳*/
        link_top[x] = top;
        if(max_son[x] != -1)
            build_link( max_son[x], top);/*優先走訪最大孩子*/

        for(int v : G[x]) {
            if( v == max_son[x] || v == pa[x] )continue;
            build_link(v, v);
        }
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
            seg.modify(1, 0, n, link[ta], link[a]+1, c);
            a = pa[ta];
            ta = link_top[a];
        }
        //a, b are on the same chain
        if( a == b )
            seg.modify(1, 0, n, link[a], link[a]+1, c) ;
            // interval [ link[a], link[a] ], if operate on edges => no edge
        else {
            if(dep[a]>dep[b])
                swap(a,b);
            //interval [ link[a],link[b] ]
            // if operate on edges ==> [ link[ max_son[a] ], link[b] ]
            seg.modify(1, 0, n, link[ a ], link[b]+1, c);
        }
    }

    /// Heavy Light Decomposition
    void HLD() {
        // root is indexed 0 here !
        find_max_son(0);
        build_link(0, 0);
    }
}tree;
int n;

int main() {
    n = getint();
    tree.init(n);
    for(int i = 1; i < n; i++) 
        tree.addEdge(p[i], i);
    tree.HLD();
    // query using tree.seg.query( tree.link[index] )
}

