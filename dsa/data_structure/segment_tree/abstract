#define MAXN maxn
struct segment_tree{
    #define right(x) x << 1 | 1
    #define left(x) x << 1
    int* arr;
    int m[4*MAXN], M[4*MAXN];
    LL sum[4*MAXN];
    int tag[4*MAXN];
    const int inf = 1e9;
    //sometimes needed
    void init() {
        //memset(tag, -1, sizeof(tag));
        fill(tag, tag+4*MAXN, inf);
    }
    void pull(int ind) {
            sum[ind] = sum[right(ind)] + sum[left(ind)];
            m[ind] = min(m[right(ind)] ,m[left(ind)]);
            M[ind] = max(M[right(ind)] ,M[left(ind)]);
    };
    void push(int ind) {
        if(tag[ind] != inf) {
            tag[left(ind)] = min(tag[left(ind)], tag[ind]);
            tag[right(ind)] = min(tag[right(ind)], tag[ind]);
            m[left(ind)] = min( m[left(ind)], tag[left(ind)]);
            m[right(ind)] = min( m[right(ind)], tag[right(ind)]);
            
            //the answer of the left(ind) and right(ind) should be correct at this point
            tag[ind] = inf;
        }
    }
    /// root => 1
    void build(int ind, int l, int r) {

        if( r - l == 1) {
            m[ind] = M[ind] = 0;
            sum[ind] = 0;
            tag[ind] = inf;
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
        
        int mid = (L+R)>>1;
        return min( query_min(left(ind), L, mid, ql, qr), query_min(right(ind), mid, R, ql, qr));
    }
    int query_max(int ind, int L, int R, int ql, int qr) {
        if( L >= qr || R <= ql ) return -1e9;
         if( R <= qr && L >= ql ) {
            return M[ind];
        }
        
        int mid = (L+R)>>1;
        return max( query_max(left(ind), L, mid, ql, qr), query_max(right(ind), mid, R, ql, qr));
    }
    //int query_sum
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
            // depends on what you modify
           
            return;
        }
        push(ind);
        int mid = (L+R)>>1;
        modify(left(ind), L, mid, ql, qr, x); modify(right(ind), mid, R, ql, qr, x);
        pull(ind);
    }
}seg;
