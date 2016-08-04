// 最小帶權匹配~ km算法
//http://acm.csie.org/ntujudge/contest_view.php?id=836&contest_id=449
#include <bits/stdc++.h>
using namespace std;
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
#define mem(x, y) memset(x, y, sizeof(x))
//const int inf = 0x7fffffff; //beware overflow
//const LL  INF = 0x7fffffffffffffff; //beware overflow
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


#define maxn 602
#define INF 0xfffffff

int sx[maxn], sy[maxn], mat[maxn][maxn];
int x[maxn], y[maxn], link[maxn];
int N, M, slack;

int DFS(int t)
{
    int tmp;
    sx[t] = 1;
    for (int i = 0; i < M; i++)
    {
        if (!sy[i])
        {
            tmp = x[t] + y[i] - mat[t][i];
            if (tmp == 0)
            {
                sy[i] = 1;
                if (link[i] == -1 || DFS(link[i]))
                {
                    link[i] = t;
                    return 1;
                }
            }
            else if (tmp < slack)
                slack = tmp;
        }
    }
    return 0;
}
int KM()
{
    for (int i = 0; i < N; i++)
    {
        x[i] = 0;
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] > x[i])
                x[i] = mat[i][j];
        }
    }
    for (int j = 0; j < M; j++)
    {
        y[j] = 0;
    }
    memset(link, -1, sizeof(link));
    for (int i = 0; i < N; i++)
    {
        while (1)
        {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            slack = INF;
            if (DFS(i)) break;
            for (int j = 0; j < N; j++)
            {
                if (sx[j])
                    x[j] -= slack;
            }
            for (int j = 0; j < M; j++)
            {
                if (sy[j])
                    y[j] += slack;
            }
        }
    }

    int ans = 0;
    int cnt = 0;
    int t;
    for (int i = 0; i < M; i++)
    {
        t = link[i];
        if (t >= 0 && mat[t][i] != -INF)
        {
            cnt ++;
            ans += mat[t][i];
        }
    }
    // 最大權 : 沒有負號
    printf("%d\n", -ans);
    return ans;
}

int t[maxn][maxn];
int main(){
    int n,E;
    while (scanf("%d", &n) != EOF)
    {
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                mat[i][j] = -INF;
        
         N = M = n;
        for(int i = 0;i < n;i ++)
                for(int j = 0; j < n; j++)
                    scanf("%d", &t[i][j]);

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j =0;j<n;j++)
                sum += t[j][i];

            for(int j=0;j<n;j++) {
                // 最大權 : 沒有負號
                mat[i][j] = -(sum-t[j][i]);
            }
            debug("\n");
        }

        KM();

    }
    return 0;
}
