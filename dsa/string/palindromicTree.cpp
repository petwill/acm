/**
    template

    len 表示所代表的回文子字串長度
    next[c] 表示所代表的回文子字串在頭尾各增加一個字符c後的回文字串其節點編號
    sufflink 表示所代表的回文子字串不包括本身的最長後綴回文子串的節點編號
    cnt 表示所代表的回文子字串在整體字串出現的次數
    the current node stands for the palindromic substring s[l..r]
**/
struct palindromic_tree{
    /* to do */
    #define MAXN  105000
    //input
    char s[MAXN]; int len;
    //
    struct node {
        int next[26];
        int len;
        int sufflink;
        int cnt, l, r;
    };
    node tree[MAXN];
    int num;            // node 1 - root with len -1, node 2 - root with len 0
    int suff;           // max suffix palindrome
    bool addLetter(int pos) {
        int cur = suff, curlen = 0;
        char let = s[pos]-'a';
        while (true) {
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
                break;
            cur = tree[cur].sufflink;
        }
        if (tree[cur].next[let]) {
            suff = tree[cur].next[let];
            tree[suff].cnt ++;
            return false;
        }

        num++;
        suff = num;
        tree[num].len = tree[cur].len + 2;
        tree[num].r = pos;
        tree[num].l = pos - tree[num].len + 1;
        tree[cur].next[let] = num;
        if (tree[num].len == 1) {
            tree[num].sufflink = 2;
            tree[num].cnt = 1;
            return true;
        }
        tree[num].cnt ++;
        while (true) {
            cur = tree[cur].sufflink;
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                tree[num].sufflink = tree[cur].next[let];
                break;
            }
        }
        return true;
    }
    void initTree() {
        num = 2; suff = 2;
        tree[1].len = -1; tree[1].sufflink = 1;
        tree[2].len = 0; tree[2].sufflink = 1;
        tree[1].cnt = tree[2].cnt = 0;
    }
    vector<int> adj[MAXN];
    void dfs( int u ) {
        for( auto it: adj[u] ) {
            dfs(it);
            tree[u].cnt += tree[it].cnt;
         }
    }
    inline void count(){ //cnt必須要在構造完後呼叫count()去計算
        for(int i=2; i<=num; i++) {
           adj[tree[i].sufflink].pb(i);
        }
        dfs(1);
    }
}ptree;
/** end template **/
