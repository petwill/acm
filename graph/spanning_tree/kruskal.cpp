#include <bits/stdc++.h>
#define LL long long
#define maxn 10002

using namespace std;

int N, M, E;
//int adj[maxn][maxn];
int par[maxn], r[maxn];
struct edge {
    int u, v;
    long long cost;
}e[100005];


void init() {
    for(int i=1;i<=N;i++)
        par[i] = i, r[i] = 0;
}
int Find(int x){
    return (x==par[x])?x:par[x]=Find(par[x]);
}
void unite(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(r[x] < r[y])
        par[x] = y;
    else {
        par[y] = x;
        if(r[x] == r[y]) r[x]++;
    }
}
bool same(int x,int y){
    return Find(x) == Find(y);
}

void addedge(int a, int b, int c){
    /*if(adj[a][b]!=-1){
        if(e[adj[a][b]].cost > (LL)c)
            e[adj[a][b]].cost = c;
    }
    */
        //adj[a][b] = adj[b][a] = E;
        e[E].u = a;
        e[E].v = b;
        e[E].cost = (LL)c;
        E++;

}
bool cmp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}
LL kruskal(){
    init();
    sort(e, e+E, cmp);
    LL res = 0;
    for(int i = 0; i < E; i++){
        if(!same(e[i].u, e[i].v)){
            unite(e[i].u, e[i].v);
            res += e[i].cost;
        }
    }
    return res;
}
int main(){
    int T;cin>>T;
    while(T--){
        int M;cin>>N>>M;
        //memset(adj, -1, sizeof(adj));
        E = 0;
        while(M--){
            int a,b,c;scanf("%d%d%d", &a, &b, &c);
            addedge(a, b ,c);
        }
        LL ans = kruskal();
        cout << ans << endl;
    }
    return 0;
}
