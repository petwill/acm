#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
#define INF 0x7fffffff
#define LL long long
#define MID(a, b)  a+(b-a)/2
#define MAX_E  50000 + 10
#define MAX_N  10000 + 10


int pa[2*MAX_N], rank[2*MAX_N];       //并查集
void init_union_find(int V){
    for(int i=0; i<V; i++){
        pa[i] = i;
        rank[i] = 0;
    }
}

int find(int x){
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        if(rank[x] < rank[y]) pa[x] = y;
        else{
            pa[y] = x;
            if(rank[x] == rank[y]) rank[x] ++;
        }
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

struct edge{ int u, v, cost; };

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

edge es[MAX_E];
int V, E;

long long kruskal(){              //kruskal算法
    sort(es, es+E, cmp);
    init_union_find(V);
    long long ans = 0;
    for(int i=0; i<E; i++){
        edge e = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            ans += e.cost;
        }
    }
    return ans;
}

int N, M, R;

int main(){
    #ifdef sxk
        freopen("in.txt", "r", stdin);
    #endif // sxk

    int t, x, y, d;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &N, &M, &R);
        V = N + M;
        E = R;
        for(int i=0; i<R; i++){
            scanf("%d%d%d", &x, &y, &d);
            es[i].u = x;                     //这三句赋值，也可以换成es[i] = (edge){ x, y+N, -d };不过只能在用G++交才可以过，C++会CE
            es[i].v = N + y;
            es[i].cost = -d;
        }
        printf("%lld\n", 10000 * (N + M) + kruskal());
    }
    return 0;
}
