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
vector<int> g[maxn]; 
stack<int> Stack;
int scnt, Time;
int belong[maxn], dfn[maxn], low[maxn], indegree[maxn];
bool instack[maxn];
void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b; scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
}
void init() {
	scnt = Time = 0;
	for(int i = 1; i <= n; i++)
		g[i].clear();
	while(!Stack.empty()) Stack.pop();
	memset(indegree, 0, sizeof(indegree));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, false, sizeof(instack));
}
void dfs(int u) {
	dfn[u] = low[u] = ++Time;
	Stack.push(u); instack[u] = true; 
	for(int v : g[u]) {
		if ( !dfn[v] ) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		scnt++;	
		int tp;
		do{
			tp = Stack.top(); Stack.pop();
			instack[tp] = false;
			belong[tp] = scnt;
		} while(tp != u);
	}
}
void tarjan() {
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			dfs(i);
}
int main(){
	int T;cin >> T;
	while(T--){
		init();
		input();
		tarjan();
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
