struct SCC{
    #define maxn 1005
    vector<int> G[maxn];
    stack<int> Stack;
    int scnt, Time;
    int belong[maxn], dfn[maxn], low[maxn];
    bool instack[maxn];
    void init(int n) {
        scnt = Time = 0;
        for(int i = 0; i < n; i++) G[i].clear();
        while(!Stack.empty()) Stack.pop();
        memset(dfn, 0, sizeof(dfn));
        memset(instack, false, sizeof(instack));
    }
    void dfs(int u) {
        dfn[u] = low[u] = ++Time;
        Stack.push(u); instack[u] = true;
        for(int v : G[u]) {
            if ( !dfn[v] ) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(instack[v])
                low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]) {
            scnt++;
            int tp;
            do{
                tp = Stack.top(); Stack.pop();
                instack[tp] = false;
                belong[tp] = scnt;
            } while(tp != u);
        }
    }
    void tarjan(int n) {
        //zero based here
        for(int i = 0; i < n; i++)
            if(!dfn[i])
                dfs(i);
    }
};
