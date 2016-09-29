//http://acm.csie.org/ntujudge/contest_view.php?id=370&contest_id=466
#include <bits/stdc++.h>
using namespace std;
//带花树,Edmonds's matching algorithm,一般图最大匹配
// have to be a undirected graph
#define MAXN 505
vector<int>G[MAXN];//用vector存圖
int pa[MAXN],match[MAXN],st[MAXN],S[MAXN],vis[MAXN];
int t,n;
inline int lca(int u,int v){//找花的花托
    for(++t;;swap(u,v)){
        if(u==0)continue;
        if(vis[u]==t)return u;
        vis[u]=t;//這種方法可以不用清空vis陣列
        u=st[pa[match[u]]];
    }
}
#define qpush(u) q.push(u),S[u]=0
inline void flower(int u,int v,int l,queue<int> &q){
    while(st[u]!=l){
        pa[u]=v;//所有未匹配邊的pa都是雙向的
        if(S[v=match[u]]==1)qpush(v);//所有奇點變偶點
        st[u]=st[v]=l,u=pa[v];
    }
}
inline bool bfs(int u){
    for(int i=1;i<=n;++i)st[i]=i;//st[i]表示第i個點的集合
    memset(S+1,-1,sizeof(int)*n);//-1:沒走過 0:偶點 1:奇點
    queue<int>q;qpush(u);
    while(q.size()){
        u=q.front(),q.pop();
        for(size_t i=0;i<G[u].size();++i){
            int v=G[u][i];
            if(S[v]==-1){
                pa[v]=u,S[v]=1;
                if(!match[v]){//有增廣路直接擴充
                    for(int lst;u;v=lst,u=pa[v])
                        lst=match[u],match[u]=v,match[v]=u;
                    return 1;
                }
                qpush(match[v]);
            }else if(!S[v]&&st[v]!=st[u]){
                int l=lca(st[v],st[u]);//遇到花，做花的處理
                flower(v,u,l,q),flower(u,v,l,q);
            }
        }
    }
    return 0;
}
inline int blossom(){
    memset(pa+1,0,sizeof(int)*n);
    memset(match+1,0,sizeof(int)*n);
    int ans=0;
    for(int i=1;i<=n;++i)
        if(!match[i]&&bfs(i))++ans;
    return ans;
}
void solve() {
    cin>>n;
    int m;cin>>m;
    while(m--) {
        int a,b;
        scanf("%d %d", &a, &b);
        a++, b++;
        // since node indexed [ 1 .. n ] in this template
        #define pb push_back
        //Multiedge and self-cycles are not forbidden
        G[a].pb( b );
        G[b].pb( a );
    }
    cout<< blossom() <<endl;
    for(int i = 1; i <= n; i++) G[i].clear();
}
int main() {
    int t;cin>>t;
    while(t--) solve();
}
