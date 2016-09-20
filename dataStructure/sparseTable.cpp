//codeforces 689D
#define maxn 200005

template< typename T, typename Cmp = less<T> >
struct RMQ {
    T d[maxn][20];
    Cmp cmp;
    int w[maxn], sz;

    void init(const T *a, int n) {
        int i, j;

        for (w[0] = -1, i = 1; i <= n; ++i) w[i] = (i & (i - 1)) ? w[i - 1] : w[i - 1] + 1;
        for (sz = n, i = 0; i < n; ++i) d[i][0] = a[i];
        for (j = 1; (1 << j) <= n; ++j) {
            for (i = 0; i + (1 << j) <= n; ++i) {
                d[i][j] = cmp(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]) ? d[i][j - 1] : d[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    // index of a [l .. r]
    const T &query(int l, int r) const {
        int x = w[r - l + 1];
        return cmp(d[l][x], d[r - (1 << x) + 1][x]) ? d[l][x] : d[r - (1 << x) + 1][x];
    }
};
int a[maxn], b[maxn];
int n;
RMQ<int> s;
RMQ<int, greater<int> > t;

int main() {
    cin>>n;
    for(int i = 0;i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    s.init(b, n);
    t.init(a, n);
    int c, d;
    LL ans = 0;
    for(int i=0;i<n;i++) {

        if( a[i] > b[i]) continue;

        int ub = n+1, lb = i;
        while( ub-lb>1) {
            int mid = (ub+lb)>>1;
            if( t.query(i, mid-1) - s.query(i, mid-1) > 0) ub = mid;
            else lb = mid;
        }
        int up = ub;

        ub = n+1, lb = i;
         while( ub-lb>1) {
            int mid = (ub+lb)>>1;
            if( t.query(i, mid-1) - s.query(i, mid-1) >= 0) ub = mid;
            else lb = mid;
        }
        int down = ub;
        ans += up-down;
    }
    cout << ans << endl;

    return 0;
}

