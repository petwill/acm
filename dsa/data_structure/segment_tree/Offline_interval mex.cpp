#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 100000 + 10;

struct Seg {
	int val;
	Seg *tl, *tr;

	Seg() :
		val(0), tl(NULL), tr(NULL) {}

	void add(int k, int x, int l, int r) {
		if(l == r)	val = x;
		else {
			int mid = (l+r) / 2;
			if(k <= mid) {
				tl->add(k, x, l, mid);
			}
			else {
				tr->add(k, x, mid+1, r);
			}
			val = min(tl->val, tr->val);
		}
	}

	int query(int k, int l, int r) {
		if(l == r)	return l;

		int m = (l+r) / 2;
		if(tl->val < k)	return tl->query(k, l, m);
		else	return tr->query(k, m+1, r);
	}
} *tree;

struct Query {
	int l, r, i;

	bool operator<(const Query &b) const {
		if(r != b.r)	return r < b.r;
		return l < b.l;
	}
} qs[MAXN];

Seg* init(int l, int r) {
	Seg* t = new Seg();
	if(l < r) {
		int m = (l+r) / 2;
		t->tl = init(l, m);
		t->tr = init(m+1, r);
	}
	return t;
}

int a[MAXN], ans[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		for(int i=1; i<=n; i++)	scanf("%d", a+i);

		tree = init(0, MAXN);

		for(int i=0; i<q; i++) {
			scanf("%d%d", &qs[i].l, &qs[i].r);
			qs[i].i = i;
		}
		sort(qs, qs+q);
		int p = 1;
		for(int i=0; i<q; i++) {
			while(p <= qs[i].r) {
				tree->add(a[p], p, 0, MAXN);
				p++;
			}

			ans[qs[i].i] = tree->query(qs[i].l, 0, MAXN);
		}

		for(int i=0; i<q; i++)	printf("%d\n", ans[i]);
	}

	return 0;
}
