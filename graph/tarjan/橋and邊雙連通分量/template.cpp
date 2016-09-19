

/** needed for tarjan **/
#define maxn 100005
#define maxm 100005
int n, m;
int dfn[maxn], low[maxn];
stack<int> st;
int Time;
int bcnt;
vector<int> G[maxn];
bool in_cyc[maxn];
/** **/

void tarjan(int s, int p){
    dfn[s] = low[s] = ++Time;
    st.push(s);
    for(int to : G[s]) if( to != p ){
        if(!dfn[to]) {
            tarjan(to, s);
            low[s] = min(low[s], low[to]);
            if( low[to] > dfn[s]) {
                // is cut_edge
                // pop stack 的過程也可以寫在這
                // 但最後(after tarjan)還要多判stack not empty的情況
                /*
                if( low[to] > dfn[s]) {

                in_cyc[bcnt] = st.top()!=to;
                while(1){
                    int t = st.top();st.pop();
                    id[t] = bcnt;
                    if(t == to) break;
                }
                bcnt++;
                */
            }

            }
        }else 
            low[s] = min(low[s], dfn[to]);
    }
   
    if(low[s] == dfn[s]){
        in_cyc[bcnt] = st.top()!=s;
        while(1){
            int t = st.top();st.pop();
            id[t] = bcnt;
            if(t == s) break;
        }
        bcnt++;
    }
}
void init_tarjan() {
    Time = bcnt = 0;
}
int main() {
  cin >> n >> m;
  init_tarjan();
  for(int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].pb(b), G[b].pb(a);
  }
  mem( in_cyc , false);
  tarjan(1, 1);

}
