// codeforces 671 Ultimate Weirdness of an array
#include <bits/stdc++.h>
using namespace std;
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
const int mod = 1e9+7;
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

#define maxn 200005
int n;
int nxt[maxn], a[maxn];
vector<int> v[maxn];
class segment_tree{
public:
    struct node{
        node *left, *right;
        int l, r, M, m, tag;
        LL sum;
        node(int L, int R) {
            left = right = NULL;
            l = L, r = R;
            sum = m = M = tag = 0;
        }
        void pull() {
            sum = left->sum + right->sum;
            m = min(left->m ,right->m);
            M = max(left->M, right->M);
        }
        void push() {
            if(tag) {
                left->tag = left->m = left->M = tag;
                right->tag = right->m = right->M = tag;
                left->sum = (LL)(left->r - left->l)*tag;
                right->sum = (LL)(right->r - right->l)*tag;
                tag = 0;
            }
        }
    };
    node *root;
    node* build(int l, int r) {
        node *n = new node(l, r);
        if( r - l == 1) { n->sum = nxt[l]; return n; }
        int mid = (l+r)>>1;
        n->left = build( l, mid );
        n->right = build( mid, r );
        n->sum = n->left->sum + n->right->sum;
        return n;
    }
    void update(node *cur, int L, int R, int val) {
        if( L >= R ||  cur->l >= R || cur->r <= L || val <= cur->m) return;

        if( cur->r <= R && cur->l >= L && cur->M <= val) {
            cur->tag = cur->m = cur->M = val;
            cur->sum = (LL)(cur->r - cur->l)*val;
            return ;
        }
        cur->push();
        update(cur->left, L, R, val);
        update(cur->right, L, R, val);
        cur->pull();
    }
}seg;
void process(int ind) {
    int num = a[ind];
    for(int i = 1; i*i <= num ; i++) {
        if( num%i == 0 && i*i != num) {
            v[i].pb( ind );
            v[num/i].pb( ind );
        }
        else if( num%i == 0 && i*i == num)
            v[i].pb( ind );
    }
}
LL ans[maxn];
const int N = maxn;
int main() {
    //IOS;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        process(i);
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++) nxt[i] = i;
    seg.root = seg.build(1, n+1);
    for(int i = maxn-2; i >= 0; i--) {
        if( v[i+1].size() >= 2 ){
            sort(all(v[i+1]));
            int sz = v[i+1].size();
            seg.update(seg.root, 1, v[i+1].front()+1, v[i+1][sz-2]);
            seg.update(seg.root, v[i+1].front()+1, v[i+1][1]+1, v[i+1].back());
            seg.update(seg.root, v[i+1][1]+1, n+1, n+1);
        }
        ans[i] = (LL)n*(n+1) - seg.root->sum;
    }
    LL tot = 0;
    for(int i = 1; i <= N-2; i++) tot += (LL)(ans[i]-ans[i-1])*i;
    cout << tot << endl;
    return 0;
}

