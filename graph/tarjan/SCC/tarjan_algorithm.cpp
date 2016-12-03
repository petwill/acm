/**
BCC
一、執行DFS。
二、執行過程中，針對每一個點，
　　計算以該點為根的子樹，所能回到的最高祖先。
三、在回溯階段時，
　　每當發現以某一點為根的子樹，已經形成一個完整的BCC，就紀錄起來。

SCC
一、執行DFS。
二、執行過程中，針對每一個點，
　　計算以該點為根的子樹，所能回到的最高祖先。
　　（forward edge和cross edge可能連往已經移除的SCC，不得計算。）
三、在回溯階段時，
　　每當發現以某一點為根的子樹，已經形成一個完整的SCC，
　　則馬上從目前的DFS Forest上面移除此SCC，
　　並且將此SCC儲存到其他地方。
**/

#define maxn 100005

int n;
vector<int> G[maxn];
stack<int> Stack;
int scnt, Time;
int belong[maxn], dfn[maxn], low[maxn];
bool instack[maxn];

void init() {
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
        int tp;
        do{
            tp = Stack.top(); Stack.pop();
            instack[tp] = false;
            belong[tp] = scnt;
        } while(tp != u);
        scnt++;
    }
}
void tarjan() {
    for(int i = 0; i < n; i++)
        if(!dfn[i])
            dfs(i);
}

int main(){
  
	int T=1;
//    cin >> T;
	while(T--){
        n = getint();
	init();
        //addEdge
	tarjan();
        // belong => [ 0 .. scnt )
}
