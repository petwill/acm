#include <bits/stdc++.h>

using namespace std;
bool vis[1005];
bool table[1005][1005];
int bff[1005];
vector<int> rbff[1005];
int n;

int dfs( int u ) {
    vis[u] = true;
    int maxdep = 0;
    for(int v : rbff[u]) {
        if( !vis[v] )
            maxdep = max( maxdep, dfs(v));
    }
    return maxdep+1;
}

int main() {

    freopen("out", "w", stdout);
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        printf("Case #%d: ", qq);
        scanf("%d", &n);
        for(int i=1;i<=n;i++) rbff[i].clear();
        memset(table, false, sizeof(table));
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d", &a);
            bff[i] = a; table[i][a]=true;
            rbff[a].push_back(i);
        }
        int ans = 0;

        for(int i=1;i<=n;i++) {
            memset(vis, false, sizeof(vis));
            int cur = i, sz = 0, prev=-1;
            while(1) {
                assert(vis[cur] == false);
                vis[cur] = true;sz++;

                if(bff[cur] == i) ans = max(ans, sz);
                if(bff[cur] == prev ){

                    sz += dfs( cur )-1;
                    ans = max(ans, sz);
                    break;
                }
                prev = cur;cur = bff[cur];if(vis[cur]) break;
            }
        }
        memset(vis, false, sizeof(vis));
        int cnt = 0;
         for(int i=1;i<n;i++){
             for(int j = i+1; j<=n;j++)
                if(table[i][j] && table[j][i] && !vis[i] && !vis[j]){
                    vis[i] = vis[j] = true;
                    cnt += (dfs(i)+dfs(j));
                }
        }
        //cout << ans << endl;
        cout << max(cnt, ans) << endl;
    }
	return 0;
}

