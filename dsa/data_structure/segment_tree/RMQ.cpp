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

#define MAXN 200005
struct segment_tree{
    #define right(x) x << 1 | 1
    #define left(x) x << 1
    int* arr;
    int m[4*MAXN], M[4*MAXN];

    void pull(int ind) {
            //sum = left->sum + right->sum;
            m[ind] = min(m[right(ind)] ,m[left(ind)]);
            M[ind] = max(M[right(ind)] ,M[left(ind)]);
    };
    /// root => 1
    void build(int ind, int l, int r) {

        if( r - l == 1) { m[ind] = M[ind] = arr[l]; return; }
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
}seg[2];

#define maxn 200005
int a[maxn], b[maxn];
int n;

int main() {
    cin>>n;
    for(int i = 0;i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    seg[0].arr = a;
    seg[0].build(1, 0, n);
    seg[1].arr = b;
    seg[1].build(1, 0, n);
    LL ans = 0;
    for(int i=0;i<n;i++) {

        if( a[i] > b[i]) continue;

        int ub = n+1, lb = i;
        while( ub-lb>1) {
            int mid = (ub+lb)>>1;
            if( seg[0].query_max(1, 0, n, i, mid) - seg[1].query_min(1, 0, n, i, mid) > 0) ub = mid;
            else lb = mid;
        }
        int up = ub;

        ub = n+1, lb = i;
         while( ub-lb>1) {
            int mid = (ub+lb)>>1;
            if( seg[0].query_max(1, 0, n, i, mid) - seg[1].query_min(1, 0, n, i, mid) >= 0) ub = mid;
            else lb = mid;
        }
        int down = ub;
        ans += up-down;
    }
    cout << ans << endl;

    return 0;
}

