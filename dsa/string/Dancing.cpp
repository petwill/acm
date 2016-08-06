//http://acm.csie.org/ntujudge/contest_view.php?id=2579&contest_id=449
// ntu judge dancing
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
//#define DEBUG
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
using namespace std;

#define maxn 2*50005
int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}

int wa[maxn],wb[maxn],ws[maxn],wv[maxn];
int Rank[maxn],height[maxn];
void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]] = i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

char str[maxn];
int sa[maxn], r[maxn];
int start[maxn], tail[maxn];
int process(int n) {
    // there are n strings
    int tot = 0;
    for(int q = 1; q <= n; q++) {
        start[q] = tot;
        scanf("%s",str+tot);
        tot += 1+strlen(str+tot);
        tail[q] = tot-1;
    }
    for(int i = 0; i < tot; i++) r[i] = (int)str[i];
    DA(r,sa,tot,128);  //注意区分此处为n+1,因为添加了一个结尾字符用于区别比较
    #if 0
        printf("%d\n", tot);
        for(int i = 0; i < tot; i++) {
            int cur = sa[i];
            while( r[cur] ) {
                char c = r[cur++];
                putchar(c);
            }
            printf(" %d\n", sa[i]);
        }
    #endif // DEBUG
    return tot;
}

/** template for query how many kinds of number between[a..b] in array[l..r] **/
//http://morris821028.github.io/2015/06/27/zj-b414/
//using  塊狀練表

const int MAXN = maxn;
const int MAXV = maxn;
const int MAXQ = 50005;
const int MAXSQRTV = 512;
class Offline {
public:
    struct Event {
        static int PILE, belong[MAXV];
        int l, r, x, y, qid;
        Event(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0):
            l(a), r(b), x(c), y(d), qid(e) {}
        bool operator<(const Event &x) const {
            if (belong[l] != belong[x.l])
                return l < x.l;
            return r < x.r;
        }
    };
    int A[MAXN], N, qsize;
    Event event[MAXQ];
    int ret[MAXQ];
    void init(int N) {
        this->N = N, qsize = 0;
        memset(pile, 0, sizeof(pile));
        memset(val_count, 0, sizeof(val_count));
        val_PILE = Event::PILE = sqrt(N);
        for (int i = N; i >= 1; i--)
            val_belong[i] = Event::belong[i] = (i / Event::PILE );
    }
    void q_add(int l, int r, int a, int b) {
        event[qsize] = Event(l, r, a, b, qsize);
        qsize++;
    }
    void run() {
        sort(event, event+qsize);

        int l = 1, r = 0;
        for (int i = 0; i < qsize; i++) {
            while (r < event[i].r)	r++, update(A[r], 1);
            while (r > event[i].r)	update(A[r], -1), r--;
            while (l > event[i].l)	l--, update(A[l], 1);
            while (l < event[i].l)	update(A[l], -1), l++;
            ret[event[i].qid] = query(event[i].x, event[i].y);
        }
    }
private:
    // unrolled
    int pile[MAXSQRTV], val_count[MAXV], val_belong[MAXV], val_PILE;
    inline void update(int x, int val) {
        val_count[x] += val;
        if (val == -1 && val_count[x] == 0)
            pile[val_belong[x]]--;
        if (val == 1 && val_count[x] == 1)
            pile[val_belong[x]]++;
    }
    int query(int a, int b) {
        int ret = 0;
        if (val_belong[a] == val_belong[b]) {
            for (int i = a; i <= b; i++)
                ret += val_count[i] > 0;
            return ret;
        }
        for (int i = val_belong[a]+1; i < val_belong[b]; i++)
            ret += pile[i];
        for (int i = (val_belong[a]+1)*val_PILE-1; i >= a; i--)
            ret += val_count[i] > 0;
        for (int i = (val_belong[b])*val_PILE; i <= b; i++)
            ret += val_count[i] > 0;
        return ret;
    }
} off;
int Offline::Event::PILE = 16, Offline::Event::belong[MAXV];
/** end template **/

char tmp[maxn];
void solve(int n, int m) {
    // n is the length of the total concatenate string
    // including ending character 0

    off.init(n-1);
    for (int i = 1; i < n; i++) {
        off.A[i] = sa[i];
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", tmp);
        int len = strlen(tmp);
        assert( tmp[len] == 0);

        int lb = -1, ub = n;
        while(ub-lb>1) {
            int mid = (lb+ub)>>1;
            if( strcmp(tmp, str+sa[mid]) <= 0 ) ub = mid;
            else lb = mid;
        }
        int l = ub;
        debug("left = %d\n", l);
        tmp[len] = 127; tmp[len+1] = 0;
        lb = -1, ub = n;
        while(ub-lb>1) {
            int mid = (lb+ub)>>1;
            if( strcmp(tmp, str+sa[mid]) < 0 ) ub = mid;
            else lb = mid;
        }
        int r = ub;
        debug("right = %d\n", r);
        int a, b; scanf("%d %d", &a, &b);

        off.q_add(l, r-1, start[a], tail[b]);
    }

    off.run();
    for (int i = 0; i < m; i++)
        printf("%d\n", off.ret[i]);
}





int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        solve( process(n), m);
    }
    return 0;
}
