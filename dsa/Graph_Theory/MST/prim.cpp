#include <bits/stdc++.h>
#define LL long long
#define maxn 10050
#define INF 2000000000
using namespace std;

int cost[maxn][maxn];
bool used[maxn];
int mincost[maxn];
int N;

LL prim(){
    for(int i=1;i<=N;i++)
        mincost[i] = INF, used[i] = false;
    mincost[1] = 0;
    LL res = 0LL;
    while(1){
        int v = -1;
        for(int u = 1; u <= N; u++){
            if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v = u;
        }
        if(v==-1) break;
        used[v] = true;
        res += (LL)mincost[v];
        for(int u = 1; u <= N; u++)
            mincost[u] = min(mincost[u], cost[v][u]);
    }
    return res;

}
int main(){
    int T;cin>>T;
    while(T--){
        int M;cin>>N>>M;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                cost[i][j] = INF;
        while(M--){
            int a,b,c;scanf("%d%d%d", &a, &b, &c);
            if(c < cost[a][b])
                cost[a][b] = cost[b][a] = c;
        }
        LL ans = prim();
        cout << ans << endl;
    }
    return 0;
}
