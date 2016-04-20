/***********
下面附上POJ 3352的解题思路吧：
       这道题的意思是说，给你一个无向图，然后问你至少需要添加几条边，
       可以使整个图变成边双连通分量，也就是说任意两点至少有两条路可以互相连通。
       我们这样考虑这个问题，属于同一个边双连通分量的任意点是
       至少有两条通路是可以互相可达的，因此我们可以将一个边双连通分量缩成一个点。
       然后考虑不在边双连通分量中的点，通过缩点后形成的是一棵树。
       对于一个树型的无向图，需要添加（度为1的点的个数+1）/2条边使得图成为双连通的。
       这样问题就是变成缩点之后，求图中度为1的点的个数了。
*************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
const int Max=1010;
vector<int> edge[Max];
int dfn[Max],Time;
int low[Max];
int degree[Max];
int ans;

bool exist[Max][Max];

void tarjan(int a,int fa) {

    dfn[a]=low[a]=++Time;
    for(int v : edge[a]){
        if(v!=fa)
        {
            if(dfn[v]==0)
            {
                tarjan(v,a);
                if(low[a]>low[v])
                    low[a]=low[v];
                if(dfn[a] < low[v])
                {
                    exist[a][v] = exist[v][a] = true;
                }
            }
            else
            {
                if(low[a]>dfn[v])
                    low[a]=dfn[v];
            }
        }
    }
}

int cc[Max], ccCnt;

void dfs(int fa, int u)
{
    cc[u] = ccCnt;
    for(auto v : edge[u])
        if(v != fa && !exist[u][v] && !cc[v])
            dfs(u, v);
}

int solve(int n)
{
    int i,j;
    int a,b;

    memset(cc, 0, sizeof(cc));
    ccCnt = 1;
    for(i=1; i<=n; i++){
        if(!cc[i]){
            dfs(-1, i);
            ///connected subgraph count
            ccCnt++;
        }
    }


    for(i=1;i<=n;i++)
    {
        a=i;
        for(j=0;j<edge[i].size();j++){
            b=edge[a][j];
            if(cc[a] != cc[b]){
                degree[cc[a]]++;
                degree[cc[b]]++;
            }
        }
    }
    int leaves=0;
    for(i=1;i<ccCnt;i++)
    {
        if(degree[i]==2)
        {
            leaves++;
        }
    }
    return (leaves+1)/2;
}

int main()
{
    int n,m;
    int i,a,b;
    int T;cin>>T;
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(degree,0,sizeof(degree));
        for(int i=1;i<=n;i++)
            edge[i].clear();
        while(m--){
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(dfn,0,sizeof(dfn));
        Time=0;
        memset(exist, false, sizeof(exist));
        ///start solution
        tarjan(1,-1);
        ans=solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
