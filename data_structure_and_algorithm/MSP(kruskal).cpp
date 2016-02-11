#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second

const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9+7;
#define maxn 200050

int n;
int par[maxn], r[maxn], E;
struct edge {
    int u, v;
    long long cost;
    int ind;
}e[maxn];

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
        e[E].u = a;
        e[E].v = b;
        e[E].cost = (LL)c;
        E++;
}
bool cmp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}
void init(){
    for(int i=1;i<=n;i++)
	        par[i] = i, r[i] = 0;
}
LL kruskal() {
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

}
