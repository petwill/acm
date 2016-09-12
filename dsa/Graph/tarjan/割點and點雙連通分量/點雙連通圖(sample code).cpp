///Round table warriors (acm)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
const int maxm = 1000005;

struct Edge{int s, t;};
vector<Edge> edge;

int dfn[maxn], low[maxn];
stack<int> st;
int n,m, adj[maxn][maxn];
vector<int> vec[maxn];
bool vis[maxn];
int Time;
bool vis_e[maxm];
int bcnt, mark[maxn], vbb[maxm];
vector<int> vb[maxm];
int color[maxn];
int tmp[maxn];

bool dfs2(int vb_num, int s, int co){
    color[s] = co;
    for(int i = 0; i < vec[s].size(); i++){
        int e_ind = vec[s][i];
        int to = edge[e_ind].s + edge[e_ind].t - s;
        if(vbb[e_ind] != vb_num) continue;
        if(color[to] == color[s] || (color[to]== -1 && dfs2(vb_num, to, co^1))){
            return true;
        }
   }
   return false;
}
void dfs(int s){
    dfn[s] = low[s] = ++Time;
    vis[s] = true;
    for(int i = 0; i < vec[s].size(); i++){
        int e_ind = vec[s][i];
        if(!vis_e[e_ind]){
            vis_e[e_ind] = true; st.push(e_ind);
            int to = edge[e_ind].s + edge[e_ind].t - s;
            if(!vis[to]){
                dfs(to);
                low[s] = min(low[s], low[to]);
                if(low[to] >= dfn[s]){
                    vb[bcnt].clear();
                    while(1){
                        int t = st.top();st.pop();
                        vbb[t] = bcnt;
                        vb[bcnt].push_back(t);
                        if(t == e_ind) break;
                    }
                    bcnt++;
                }
            }else
                low[s] = min(low[s], dfn[to]);
        }
    }

}
int main(){
    int T;scanf("%d", &T);
    while (T--){
        cin >> n >> m;
        ///initialize
        for(int i = 0; i <= n; i++)
            fill(adj[i], adj[i]+n+1, 1);
        memset(vis, false, sizeof(vis));
        memset(vis_e, false, sizeof(vis_e));
        memset(mark, false, sizeof(mark));
        Time = bcnt = 0;
        for(int i=1;i<=n;i++)
            vec[i].clear();
        edge.clear();
        /// start input
        while(m--){
            int a,b;scanf("%d%d", &a, &b);
            adj[a][b] = adj[b][a] = 0;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                if(adj[i][j]){
                    edge.push_back(Edge{i,j});
                    vec[i].push_back((int)edge.size()-1);
                    vec[j].push_back((int)edge.size()-1);
                }
            }
        ///start solution
        for(int i=1;i<=n;i++)
            if(!vis[i] && !vec[i].empty()){
                //while(!st.empty()) vb[bcnt].push_back(st.top()), st.pop();
                dfs(i);


                if(!st.empty()){
                    while(!st.empty()) vb[bcnt].push_back(st.top()), st.pop();
                    bcnt++;
                }

            }
        for(int i = 0; i < bcnt; i++) {
            memset(color, -1, sizeof(color));
            if(dfs2(i, edge[vb[i][0]].s ,1)) {
                  /// mark all vertex in i-th subgraph as valid
                for(int j = 0; j < vb[i].size(); j++)
                    mark[edge[vb[i][j]].s] = mark[edge[vb[i][j]].t] = true;
            }
        }
        printf("%d\n", count(mark+1, mark+1+n, false));
    }
    return 0;
}
