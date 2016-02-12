/** 592D - Super M **/
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
#define maxn 123460

int n, m;
vector<int> g[maxn];
bool is[maxn];
int dep[maxn], R, max_depth, A;
int cnt[maxn], parent[maxn];

bool dfs(int u, int par = 0){
	parent[u] = par;
	dep[u] = dep[par] + 1;
	if(dep[u] > max_depth && is[u])
		max_depth = dep[u], R = u;
	bool ret = is[u];
	for(int v : g[u]) 
		if(v != par)
			ret |= dfs(v, u);
	if(ret) A++;
	return ret;
}
			
int find_center(int start) {
	R = start; dep[0] = -1; max_depth = 0;
	dfs(start);
	max_depth = 0; dep[R] = -1;
	dfs(R, R);
	int ret = R, d = max_depth/2;
	while( d>0 ) {
		d--;
		ret = parent[ret];
	}
	return ret;
}
int S, dis, max_length;
bool dfs1(int u, int par = 0) {
	dep[u] = dep[par] + 1;
	if(is[u])	
		if(dep[u] > max_length)
			max_length = dep[u], S = u;
		else if(dep[u] == max_length && u < S) 
			S = u;

	bool c = false; 
	for(int v : g[u])
		if( v != par )
			dfs1(v, u);
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n-1; i++){
		int a, b; scanf("%d%d" ,&a, &b);
		g[a].pb(b), g[b].pb(a);
	}
	memset(is, false, sizeof(is));
	int tmp;
	for(int i = 0; i < m; i++){
		cin>>tmp;is[tmp] = true;
	}
	int C = find_center(tmp);
	dep[0] = -1;S = inf;dis = (max_depth+1)/2;
	// distance(center, any other node) <= (longestpath + 1) / 2
	dfs1(C);
	if( max_depth & 1)
		dfs1(parent[C]);
	cout << S << endl << A-2-max_depth << endl;
	return 0;
}
