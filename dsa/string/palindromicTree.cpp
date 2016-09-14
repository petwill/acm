#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
const int inf = 0x7fffffff; //beware overflow
const LL INF = 0x7fffffffffffffff; //beware overflow
#define mem(x, y) memset(x, (y), sizeof(x) );
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
     return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s << "[ ";
    for (auto it : c) s << it << " ";
    s << "]";
    return s;
}
template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    o << "{";
    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? "" : ", ") << *it;
    return o << "}";
}
template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->fi << ":" << it->se;
    }
    o << "}";
    return o;
}
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
    /* */
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
    inline void count(){ /*cnt必須要在構造完後呼叫count()去計算*/
        for(int i=num; i >= 1; i-- ){
            tree[ tree[i].sufflink ].cnt += tree[i].cnt;
        }
    }
}ptree;
/** end template **/
int main() {
    int n, q; cin >> n >> q;
    scanf("%s", ptree.s); ptree.len = strlen(ptree.s);
    assert( n == ptree.len );
    ptree.initTree();
    for(int i = 0; i < n; i++) { ptree.addLetter( i ); }
    ptree.count();
    /** go through all palindromic substrings,[ tree[i].l .. tree[i].r ]
    for(int i = 3; i <= ptree.num; i++) printf("%d %d\n", ptree.tree[i].l, ptree.tree[i].r);
    **/
   
}
