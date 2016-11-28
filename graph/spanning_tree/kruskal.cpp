#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 100020

inline LL getint(){
   LL _x=0,_tmp=1; char _tc=getchar();
   while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
   if( _tc == '-' ) _tc=getchar() , _tmp = -1;
   while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
   return _x*_tmp;
}

struct edge {
    int u, v;
    long long cost;
}e[5*maxn];


int pa[maxn], Rank[maxn];
void init(int V) {
    for(int i=0; i<V; i++) {
        pa[i] = i;
        Rank[i] = 0;
    }
} int find(int x) {
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

int unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y){
        if(Rank[x] < Rank[y]) {
            pa[x] = y;
            return y;
        }
        else{
            pa[y] = x;
            if(Rank[x] == Rank[y]) Rank[x] ++;
            return x;
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}
bool cmp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}
LL kruskal(int n, int m){
    init(n);
    sort(e, e+m, cmp);
    LL res = 0;
    for(int i = 0; i < m; i++){
        if(!same(e[i].u, e[i].v)){
            unite(e[i].u, e[i].v);
            res += e[i].cost;
        }
    }
    return res;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a,b,c;
        e[i].u = getint();
        e[i].v = getint();
        e[i].cost = getint();
    }
    cout << kruskal(n, m) << endl;
    return 0;
}
