
LL seg[1<<19];
#define le(x) (x*2+1)
#define ri(x) (x*2+2)
void build(int x=0, int l=0, int r=1<<18) {
    if( r-l == 1 ) ;
    else {
        int mid = (l+r)>>1;
        build(le(x), l, mid);
        build(ri(x), mid, r);
        seg[x] = max( seg[le(x)], seg[ri(x)]);
    }
}
LL query(int ql, int qr,int x=0, int l = 0, int r = 1<<18) {
    if( ql >= r || qr <= l ) return 0;
    if( l >= ql && r <= qr ) return seg[x];

    int mid = (l+r)>>1;
    return max( query(ql, qr, le(x), l, mid), query(ql, qr, ri(x), mid, r) );
}

int main() {
        //build on seg_arr[0 .. n )
        // ====>   (1<<18) >= n
        for(int i=0;i<(1<<18);i++)
            if( i < n )seg[ (1<<18)-1 + i ] = seg_arr[i];
            else seg[ (1<<18)-1 + i ] = 0;
        build();
       
}

