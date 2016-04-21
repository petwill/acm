/** Uva 820 **/
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second

const int inf = 0x7fffffff;
const LL  INF = 0x7fffffffffffffff;
const int mod = 1e9+7;
#define maxn 105
int n;
struct edge{ int to, cap, rev; };
vector<edge> g[maxn];
int dis[maxn], iter[maxn];
void addedge(int from, int to, int cap) {
	g[to].pb(edge{from, cap, (int)g[from].size()});
	g[from].pb(edge{to, cap, (int)g[to].size()-1});
}
bool bfs(int s, int t) {
	memset(dis, -1, sizeof(dis));
	queue<int> que;
	que.push(s); dis[s] = 0;
	while(!que.empty()) {
		int tp = que.front(); que.pop();
		for(edge e : g[tp]) {
			if(e.cap > 0 && dis[e.to] == -1)
				dis[e.to] = dis[tp] + 1, que.push(e.to);
		}
	}
	return dis[t] != -1;
}
int dfs(int v, int t, int f) {
	if( v == t ) return f;
	for(int &i = iter[v]; i < g[v].size(); i++) {
		edge &e = g[v][i];
		if(e.cap > 0 && dis[v] < dis[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {	
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				f += d;
				return d;
			}
		}
	}
	return 0;
}
int dinic(int s, int t) {
	int ret = 0;
	while( bfs(s, t) ) {
		memset(iter, 0, sizeof(iter));
		int f;
		while((	f = dfs(s, t, inf) )> 0 )
			ret += f;
	}
	return ret;
}

void init() {
	for(int i = 1; i <= n; i++)
		g[i].clear();
}

int main(){ 
	int cnt = 1;
	while(scanf("%d", &n) == 1 && n != 0) {
		init();
		int s, t, c; scanf("%d%d%d", &s, &t, &c);
		while(c--) {
			int from, to, cap; scanf("%d%d%d", &from, &to, &cap);
			addedge(from ,to, cap);
		}
		printf("Network %d\n", cnt++);
		printf("The bandwidth is %d.\n\n", dinic(s, t));
	}
	return 0;
}
