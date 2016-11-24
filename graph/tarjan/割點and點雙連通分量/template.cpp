//    regard every vbcc as a set of edges
//    so vb[i] is a vector that contains a set of edge indexes
/** needed for tarjan **/
#define maxn 100005
#define maxm 100005
int n, m;
struct Edge{int s, t;};
vector<Edge> edge;
int dfn[maxn], low[maxn];
stack<int> st;
bool vis[maxn];
int Time;
bool vis_e[maxm];
int bcnt, vbb[maxm];
vector<int> vb[maxm];
vector<int> G[maxn];
/** **/

void tarjan(int s){
    dfn[s] = low[s] = ++Time;
    vis[s] = true;
    for(int e_ind : G[s]){
        if(!vis_e[e_ind]){
            vis_e[e_ind] = true; st.push(e_ind);
            int to = edge[e_ind].s + edge[e_ind].t - s;
            if(!vis[to]){
                tarjan(to);
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
void init_tarjan() {

    mem(vis, false); mem(vis_e, false);
    Time = bcnt = 0; edge.clear();
    for(int i = 1; i <= n; i++) G[i].clear();
}

int main() {

    cin >> n >> m;
    init_tarjan();
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edge.push_back(Edge{a,b});
        G[a].push_back((int)edge.size()-1);
        G[b].push_back((int)edge.size()-1);
    }
    tarjan(1);

}
