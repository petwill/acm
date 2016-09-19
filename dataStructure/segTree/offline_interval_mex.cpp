#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 100000 + 10;
int a[maxn],n,m;
struct query{
    int ql, qr, ind;
    bool operator < (const query &cmp) const{
        if(cmp.qr != qr) return qr < cmp.qr;
        return ql < cmp.ql;
    }
}q[maxn];
struct node{
    int val;
    node *lc, *rc;
    node() : lc(NULL), rc(NULL), val(0) {}
    void pull(){
        val = min(lc->val, rc->val);
    }
};
node *build(int l, int r){
    node *now = new node();
    if(r-l==1) return now;
    int mid = (l+r)>>1;
    now->lc = build(l, mid);
    now->rc = build(mid, r);
    return now;
}
void add(node *t, int L, int R, int k, int x){
    if(R-L==1) {
        assert(L == k);
        t->val = x;
        return;
    }
    int mid = (L + R)>>1;
    if(k < mid) add(t->lc, L, mid, k, x);
    else add(t->rc, mid, R, k, x);
    t->pull();
}
int Query(node *t, int L, int R, int x){
    if(R-L==1) {assert(t->val < x);return L;}
    int mid = (L + R) >> 1;
    if(t->lc->val < x) return Query(t->lc, L, mid, x);
    else return Query(t->rc, mid, R, x);
}
int ans[maxn];
int main(){
    int T;cin>>T;
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
            scanf("%d", &a[i]);
        for(int i=0;i<m;i++)
            scanf("%d%d", &q[i].ql, &q[i].qr), q[i].ind = i;
        sort(q, q+m);
        node *root = build(0, maxn);
        int p = 1;
        for(int i=0;i<m;i++) {
            while(p <= q[i].qr){
                add(root, 0, maxn, a[p], p);
                p++;
            }
            ans[q[i].ind] = Query(root, 0, maxn, q[i].ql);
        }
        for(int i=0;i<m;i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
