#include <bits/stdc++.h>
#define pb push_back
using namespace std;

FILE *dic;
vector<string> dictionary;
unordered_set<string> dict;
int dp[50][50];
const int mod = 1e7+9;
/*
struct Hash_dict{
    vector<string> arr[mod];
    int hash(string str) {
        const int base = 37;
        int ret = 0;
        for(int i = str.size()-1; i >= 0; i--) {
            ret = (base*ret + str[i]-'a')%mod;
        }
        assert( ret >= 0);
        return ret;
    }
    void insert(string str) {
        int ind = hash(str);
        arr[ind].push_back( str );
    }
    bool find(string str) {
        int ind  = hash(str);
        for(string& s : arr[ind] )
            if( s == str ) return true;
        return false;
    }
};
struct trie{
    struct node{
        node *next[26];
        bool end;
        int dp;
        node() {
            end = false; dp = 0;
            memset(next, 0, sizeof(next));
        }
    };
    node *root;
    trie() {root = new node();}
    void insert(string str) {
        node *ptr = root;
        for(int i = 0; i < str.size(); i++) {
            int ind = str[i]-'a';
            if( ptr->next[ind] == NULL) {
               ptr->next[ind] = new node();
            }
            //ptr->cnt[ind]++;
            ptr = ptr->next[ind];
        }
        ptr->end = true;
    }
    bool find(string str) {
        node* ptr = root;
        for(int i = 0; i < str.size(); i++) {
            int ind = str[i] - 'a';
            if( ptr->next[ind] == NULL) return false;
            ptr = ptr->next[ind];
        }
        return ptr!=NULL && ptr->end;
    }
};
*/
bool edit_distance(string a, string b) {
    int n = a.size(), m = b.size();
    int tmp = n-m; if(tmp<0) tmp=-tmp;
    if( tmp > 2) return false;
    int charDic[256]; 
    memset(charDic, 0, sizeof(charDic));
    for(int i = 1; i <= n; i++) {
        int db = 0;
        for(int j = 1; j <= m; j++) {
            int i1 = charDic[ b[j-1] ];
            int j1 = db;
            int cost = 0;
            if( a[i-1] == b[j-1] ) db = j;
            else cost = 1;
            dp[i][j] = min(dp[i-1][j-1]+cost, min(dp[i-1][j]+1, dp[i][j-1]+1));
            if( i1 > 0 && j1 > 0 )
                dp[i][j] = min(dp[i][j], dp[i1-1][j1-1] + (i-i1-1) + (j-j1-1) + 1);
        }
        charDic[ a[i-1] ] = i;
    }
    return dp[n][m]<=2;
}
int main(int argc, char *argv[]) {
    dic = fopen(argv[1], "r");
    char line[1000];
    char w[50];
    while( fgets(line, 1000, dic) ) {
        if( !isalpha(line[0]) ) continue;
        sscanf(line, "%s", w);
        if(w[strlen(w)-1] == ')') continue;
        string tmp(w);
        bool flag = false;
        for(int i = 0; i < tmp.size(); i++)
            if( isalpha(tmp[i]) )  tmp[i] = tolower(tmp[i]);
            else {flag = true; break;}
        if( flag ) continue;
        dictionary.pb(tmp);
        dict.insert(tmp);
    }
    fclose(dic);

    for(int i = 1; i <= 31; i++) dp[i][0] = i;
    for(int i = 1; i <= 31; i++) dp[0][i] = i;

    while(fgets(line, 1000, stdin)) {
        sscanf(line,"%s", w);
        printf("%s ==>", w);
        string word(w);
        if( dict.find(word) != dict.end() )  { printf(" OK\n"); continue; }
        vector<string> ans;
        for(string& str : dictionary) {
             if( edit_distance(str, word) ) ans.pb( str );
        }
        for(string& str : ans) printf(" %s", str.c_str());
        if( ans.empty() ) printf(" NONE");
        putchar('\n');
    }
    return 0;
}
