//Codeforces 456D A Lot Of Games
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
const int inf = 0x7fffffff;
const LL  INF = 0x7fffffffffffffff;
const int mod = 1e9+7;
typedef vector<int> vec;
typedef vector<vec> mat;
#define maxn 100005
int x[maxn][128];
int n, k;

int dfs(int u) {
    int ans = 0;
    bool flag = false;
    for(int v = 'a'; v <= 'z'; v++) {
        if( x[u][v] != -1 ) {
            flag = true;
            ans |= ( 3^dfs( x[u][v] ));
        }
    }
    if( !flag ) ans = 1;
    return ans;
}
int main() {
#ifdef DEBUG
	freopen("out", "w", stdout);
#endif
    cin >> n >> k;
    memset(x, -1, sizeof(x));
    int sz = 1, ind = 0;
    while(n--) {
        string str; cin >> str;
        ind = 0;
        for(int i = 0; i < str.size(); i++) {
            if( x[ind][str[i]] == -1 ) ind = x[ind][str[i]] = sz++;
            else ind = x[ind][str[i]];
        }
    }
    int ans = dfs(0);
    if( ans == 0 || ans == 1 || ans == 2 && !(k&1)) puts("Second");
    else puts("First");

	return 0;
}
