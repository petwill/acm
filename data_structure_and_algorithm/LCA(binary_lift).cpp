#include <bits/stdc++.h>
using namespace std;
#define maxn 100

int n, m, l;
vector <int> g[maxn];
int tin[maxn], tout[maxn];
int timer;
int up[maxn][maxn];

void dfs (int v, int p = 0) {
	tin[v] = ++timer;
	up [v][0] = p;

	for (int i = 1; i <= l; ++ i)
		up [v] [i] = up [up [v] [i-1]] [i-1];
	for (size_t i = 0; i < g [v] .size(); ++ i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v);
	}
	tout [v] = ++ timer;
}

bool upper (int a, int b) {
	return tin [a] <= tin [b] && tout [a] >= tout [b];
}

int lca (int a, int b) {
	if (upper (a, b)) return a;
	if (upper (b, a)) return b;
	for (int i = l; i >= 0; --i){
		if (! upper (up [a] [i], b))
			a = up [a] [i];
	}
	return up [a][0];
}

int main () {
    cin >> n >> m;
    //initialize if uses dynamic memory allocation
	//tin.resize (n+1), tout.resize (n+1), up.resize (n+1);
    //for (int i = 1; i <=n; ++ i) up [i] .resize (l + 1);
    l = 1;
    while ((1 << l) <= n) ++ l;

    for(int i = 0; i < m; i++) {
        int a, b;cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    timer = 0;
    dfs (1, 1);
    int a = 5, b = 4; // The current query
    int res = lca (a, b); // Response to a request
    printf("%d\n", res);
}
