#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

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
const LL  INF = 0x7fffffffffffffff; //beware overflow
const LL mod = 1e9+7;
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

#define maxn 200001
char t[maxn];
char s[maxn * 2];
int z[maxn * 2];
int N ;
int longest_palindromic_substring() {
    // t穿插特殊字元，存放到s。
    int n = strlen(t);
    N = n * 2 + 1;
    memset(s, '.', N);
    for (int i=0; i<n; ++i) s[i*2+1] = t[i];
    s[N] = '\0';
    z[0] = 1;   // if無須使用，then無須計算。

    int L = 0, R = 0;
    for (int i=1; i<N; ++i) // 從z[1]開始
    {
        z[i] = (R > i) ? min(z[2*L-i], R-i) : 1;
        while (i-z[i] >= 0 && i+z[i] < N &&
               s[i-z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i] > R) L = i, R = i+z[i];
    }

    /*
    // 尋找最長迴文子字串的長度
    n = 0;
    int p = 0;
    for (int i=1; i<N; ++i) // 從z[1]開始
        if (z[i] > n)
            n = z[p = i];
    */
    // longest 從中心到外端的長度 => (n-2)/2
    //cout << "最長迴文子字串的長度是" << (2*n-1) / 2;

    /*
    // 印出最長迴文子字串，記得別印特殊字元。
        for (int i=p-z[p]+1; i<=p+z[p]-1; ++i)
            if (i & 1) {
                cout << s[i];
            }
    */
    return (2*n-1)/2;
}
int nxt[maxn * 2];
int main() {
    int T;cin>>T;
    while(T--) {
        scanf("%s", t);
        #ifdef DEBUG
            cout << longest_palindromic_substring() <<endl;
        #else
            longest_palindromic_substring();
        #endif
        memset(nxt, -1, sizeof(nxt));
        for(int i = 0; i < N; i++) {
            nxt[ i-z[i]+1 ] = i+1;
        }
        int leftmost = 0;
        for(int i = 0; i < N; i++) {
            leftmost = max(leftmost, nxt[i]);
            nxt[i] = max(leftmost, nxt[i]);
        }
        int ans = 0;
        for(int cur = 0; cur<N-1;) {
            cur = nxt[cur];
            ans++;
        }
        cout<< ans <<endl;
    }
    return 0;
}
