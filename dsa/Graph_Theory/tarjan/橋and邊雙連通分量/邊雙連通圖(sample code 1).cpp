/*
 * Problem: pku3177 Redundant Paths (USACO JAN06)
 * Author: Guo Jiabao
 * Time: 2009.4.7 19:37
 * State: Solved
 * Memo: 橋 雙連通分支
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string.h>
const int MAXN=5001,MAXM=10001*2*2;

using namespace std;

struct edge
{
    edge *next,*op;
    int t;
    bool vis;
}ES[MAXM];

edge *V[MAXN],*PAR[MAXN];
int N,M,EC=-1,D,Ans;
int DFN[MAXN],LOW[MAXN],Bel[MAXN],Deg[MAXN];
bool adjm[MAXN][MAXN];

inline void addedge(int a,int b)
{
    ES[++EC].next=V[a];
    V[a]=ES+EC;
    V[a]->t=b;
    V[a]->vis=false;

    ES[++EC].next=V[b];
    V[b]=ES+EC;
    V[b]->t=a;
    V[b]->vis=false;

    V[a]->op=V[b];V[b]->op=V[a];
}
void init()
{
    int i,a,b;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++)
    {
        ES[i].vis = false;
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    memset(Deg, 0, sizeof(Deg));
    memset(adjm, false, sizeof(adjm));
    memset(Bel ,0, sizeof(Bel));
}
void dfs(int u)
{
    DFN[u]=LOW[u]=++D;
    for (edge *k=V[u];k;k=k->next)
    {
        int v=k->t;
        if (k->vis) continue;
        k->vis=k->op->vis=true;
        if (!DFN[v])
        {
            PAR[v]=k->op;
            dfs(v);
            if (LOW[v]<LOW[u])
                LOW[u]=LOW[v];
        }
        else if (DFN[v]<LOW[u])
            LOW[u]=DFN[v];
    }
}
void part(int u)
{
    Bel[u]=D;
    for (edge *k=V[u];k;k=k->next)
        if (k->vis && !Bel[k->t])
            part(k->t);
}
void solve()
{
    int i,u,v,leaf=0;
    edge *k;
    dfs(1);
    for (v=2;v<=N;v++)
    {
        k=PAR[v];
        u=k->t;
        if (DFN[u]<LOW[v])
            k->vis=k->op->vis=false;//標記爲橋邊
    }
    D=0;
    for (u=1;u<=N;u++)
    {
        if (!Bel[u])
        {
            ++D;
            part(u);
        }
    }
    for (u=1;u<=N;u++)
        for (k=V[u];k;k=k->next)
            adjm[Bel[u]][Bel[k->t]]=adjm[Bel[k->t]][Bel[u]]=true;
    for (u=1;u<=D;u++)
        for (v=1;v<=D;v++)
            if (u!=v && adjm[u][v])
                Deg[u]++;

    for (i=1;i<=D;i++)
        if (Deg[i]==1)
            leaf++;
    if (leaf!=1)
        Ans=(leaf+1)/2;
    else
        Ans=0;
}
int main()
{
    int T;scanf("%d", &T);
    while(T--){
        init();
        solve();
        printf("%d\n",Ans);
    }
    return 0;
}
