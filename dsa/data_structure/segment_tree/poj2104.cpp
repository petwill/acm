#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
const int inf = 0x7fffffff;
const LL  INF = 0x7fffffffffffffff;
const int mod = 1e9+7;
typedef vector<int> vec;
typedef vector<vec> mat;
#define maxn 100005
int n, m, arr[maxn], sorted[maxn];
struct node{
    node *left, *right;
    int l, r;
    vector<int> data;
    node(int L, int R) {
        left = right = NULL;
        l = L, r = R;
        data.clear();
    }
};
class segment_tree{
public:
    node *root;
    node* build(int l, int r) {
        node *n = new node(l, r);
        if( r - l == 1) { n->data.pb( arr[l] ); return n; }
        int mid = (l+r)>>1;
        n->left = build( l, mid );
        n->right = build( mid, r );
        n->data.resize( n->left->data.size() + n->right->data.size() );
        merge( all(n->left->data), all(n->right->data), n->data.begin());
        return n;
    }
    int query(node* n, int L, int R, int k, int x) {
        if( n->r <= L || n->l >= R ) return 0;
        if( n->l >= L && n->r <= R){
            return upper_bound( all(n->data), x) - n->data.begin();;
        }
        return query(n->left, L, R, k, x) + query(n->right, L, R, k, x);
    }
}seg;
int main() {
#ifdef DEBUG
	freopen("out", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]), sorted[i] = arr[i];
    sort( sorted, sorted + n);
    seg.root = seg.build( 0, n);
    while( m-- ) {
        int L, R, k; scanf("%d%d%d", &L, &R, &k);
        L--; // [L, R)
        int lb = -1, ub = n-1;
        while( ub - lb > 1) {
            int mid = (ub+lb)>>1;
            int x = sorted[mid];
            //printf("x = %d, query = %d\n",x,  seg.query(seg.root, L, R, k, x));
            if( seg.query(seg.root, L, R, k, x ) >= k ) ub = mid;
            else lb = mid;
        }
        printf("%d\n", sorted[ub]);
    }
	return 0;
}

