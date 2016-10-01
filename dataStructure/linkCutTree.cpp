//https://github.com/yzgysjr/ACM-ICPC-Templates/blob/master/Data%20Structure/Link%20Cut%20Tree.cpp
struct node { int rev; node *pre, *ch[2]; } base[MAXN], nil, *null;
typedef node *tree;
#define isRoot(x) (x->pre->ch[0] != x && x->pre->ch[1] != x)
#define isRight(x) (x->pre->ch[1] == x)
inline void MakeRev(tree t) { if (t != null) { t->rev ^= 1; swap(t->ch[0], t->ch[1]); } }
inline void PushDown(tree t) { if (t->rev) { MakeRev(t->ch[0]); MakeRev(t->ch[1]); t->rev = 0; } }
inline void Rotate(tree x) {
	tree y = x->pre; PushDown(y); PushDown(x);
	int d = isRight(x);
	if (!isRoot(y)) y->pre->ch[isRight(y)] = x; x->pre = y->pre;
	if ((y->ch[d] = x->ch[!d]) != null) y->ch[d]->pre = y;
	x->ch[!d] = y; y->pre = x; Update(y);
}
inline void Splay(tree x) {
	PushDown(x); for (tree y; !isRoot(x); Rotate(x)) {
		y = x->pre; if (!isRoot(y)) Rotate(isRight(x) != isRight(y) ? x : y);
	} Update(x);
}
inline void Splay(tree x, tree to) {
	PushDown(x); for (tree y; (y = x->pre) != to; Rotate(x)) if (y->pre != to)
		Rotate(isRight(x) != isRight(y) ? x : y);
	Update(x);
}
inline tree Access(tree t) {
	tree last = null; for (; t != null; last = t, t = t->pre) Splay(t),t->ch[1] = last, Update(t);
	return last;
}
inline void MakeRoot(tree t) { Access(t); Splay(t); MakeRev(t); }
inline tree FindRoot(tree t) { Access(t); Splay(t); tree last = null;
	for ( ; t != null; last = t, t = t->ch[0]) PushDown(t); Splay(last); return last;
}
inline void Join(tree x, tree y) { MakeRoot(y); y->pre = x; }
inline void Cut(tree t) {Access(t); Splay(t); t->ch[0]->pre = null; t->ch[0] = null; Update(t);}
inline void Cut(tree x, tree y) {
	tree upper = (Access(x), Access(y));
	if (upper == x) { Splay(x); y->pre = null; x->ch[1] = null; Update(x); }
	else if (upper == y) { Access(x); Splay(y); x->pre = null; y->ch[1] = null; Update(y); }
	else assert(0); // `impossible to happen`
}
inline int Query(tree a, tree b) { // `query the cost in path a <-> b, lca inclusive`
	Access(a); tree c = Access(b); // c is lca
	int v1 = c->ch[1]->maxCost; Access(a);
	int v2 = c->ch[1]->maxCost;
	return max(max(v1, v2), c->cost);
}
void Init() {
	null = &nil; null->ch[0] = null->ch[1] = null->pre = null; null->rev = 0;
	Rep(i, 1, N) { node &n = base[i]; n.rev = 0; n.pre = n.ch[0] = n.ch[1] = null; }
}
//compressed version
//http://trinklee.blog.163.com/blog/static/238158060201521101957375/
const int N=30010;
int n,fa[N],son[N][2],val[N],siz[N],stmp,rev[N];
#define swap(a,b) (stmp=a,a=b,b=stmp)
void pu(int t){siz[t]=siz[son[t][0]]+siz[son[t][1]]+1;}
void pd(int t){rev[t]?rev[t]=0,rev[son[t][0]]^=1,rev[son[t][1]]^=1,swap(son[t][0],son[t][1]),1:1;}
bool nr(int t){return son[fa[t]][0]==t||son[fa[t]][1]==t;}
void rtt(int t,int f=0,bool p=0){
    p=son[f=fa[t]][1]==t,
    fa[t]=fa[f],nr(f)?son[fa[f]][son[fa[f]][1]==f]=t:1,
    (son[f][p]=son[t][!p])?fa[son[f][p]]=f:1,
    pu(son[fa[f]=t][!p]=f);
}
void pv(int t){if(nr(t))pv(fa[t]);pd(t);}
void splay(int t,int f=0){
    for(pv(t);nr(t);rtt(t))nr(f=fa[t])?
    rtt(son[f][1]==t^son[fa[f]][1]==f?t:f),1:1;pu(t);
}
void access(int t,int la=0){for(;t;splay(t),son[t][1]=la,la=t,t=fa[t]);}
void makeroot(int t){access(t),splay(t),rev[t]^=1;}
void link(int u,int v){makeroot(u),fa[u]=v;}
void cut(int u,int v){makeroot(u),access(v),splay(v),son[v][0]=fa[u]=0;}
