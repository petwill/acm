/** Uva 11504 **/
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
#define maxn 100050

int n, m;
vector<int> rg[maxn], g[maxn]; 
int scnt, stamp;
int belong[maxn], vis[maxn];
int indegree[maxn], topo[maxn];

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b; scanf("%d%d", &a, &b);
		g[a].pb(b);
		// r stands for reverse
		rg[b].pb(a);
	}
}
void init() {
	scnt = stamp = 0;
	for(int i = 1; i <= n; i++)
		rg[i].clear(), g[i].clear();
	memset(indegree, 0, sizeof(indegree));
	memset(vis, 0, sizeof(vis));
}
void dfs_stamp(int u) {
	vis[u] = true;
	for(int v : rg[u]) {
		if(!vis[v])
			dfs_stamp( v );
	}
	topo[++stamp] = u;
}
void dfs(int u) {
	vis[u] = true;
	belong[u] = scnt;
	for(int v : g[u]) {
		if( !vis[v] )
			dfs(v);
	}
}
void kosaraju() {
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs_stamp(i);
	memset(vis, false, sizeof(vis));
	for(int i = n; i > 0; i--) {
		if(!vis[topo[i]])
			scnt++, dfs(topo[i]);
	}
}
int main(){
	int T;cin >> T;
	while(T--){
		init();
		input();
		kosaraju();
		for(int i = 1; i <= n; i++) {
			for(int v : g[i]) {
				if(belong[v] != belong[i])
					indegree[belong[v]]++;
			}
		}
		LL ans = 0;
		for(int i = 1; i <= scnt; i++)	
			if(!indegree[i]) ans++;
		cout << ans << endl;
	}
	return 0;
}
