//http://codeforces.com/contest/311/problem/B
struct line{
    LL slope, inter;
    LL value(LL x) { return x*slope + inter; }
};
bool check(line x, line y, line z) {
    return (z.slope - y.slope) * (z.inter - x.inter ) >=
           ( z.slope - x.slope) * (z.inter - y.inter) ;
}

#define maxn 100005
int n, m, p;
LL a[maxn], d[maxn], dp[101][maxn], s[maxn];
int main() {
    cin>> n >> m >> p;
    for(int i = 2; i<=n; ++i) {
        d[i] = getint();
        d[i] += d[i-1];
    }
    for(int i = 1; i<=m; ++i) {
        int h; scanf("%d %lld", &h, a+i);
        a[i] -= d[h];
    }
    sort( a+1, a+1+m );
    for(int i=1;i<=m;i++) s[i] = a[i]+s[i-1];
    //start dp
    for(int i=1; i<=p;i++) {
        if( i == 1 ) {
            for(int j=1;j<=m;j++) dp[i][j] = j*a[j] - s[j];
        }else {
            deque<line> dq;
            dq.pb( {0, 0} );
            for(int j=1;j<=m;j++) {
                while( dq.size() >= 2 && dq[0].value(-a[j]) > dq[1].value(-a[j]) ) dq.pop_front();
                dp[i][j] = dq[0].value(-a[j]);

                line newline{ j, dp[i-1][j]+s[j] };
                while( dq.size() >= 2 && check(dq[dq.size()-2], dq.back(), newline) ) dq.pop_back();
                dq.pb( newline );
            /*
                if( i==1 ) {
                    dp[i][j] = j*a[j] - s[j];
                }else {
                    LL mn = 0;
                    for(int k = 1; k < j; k++) {
                        mn = min(mn, dp[i-1][k] + s[k] - a[j]*k );
                    }
                    dp[i][j] = mn + a[j]*j-s[j];
                    // apply convex hull optimization
                }
            */
                dp[i][j] += a[j]*j - s[j];
            }
        }
    }
    cout << dp[p][m] << endl;
}

