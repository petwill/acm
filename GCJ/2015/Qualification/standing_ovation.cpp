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
#define maxn
int main() {
#ifdef DEBUG
	freopen("out", "w", stdout);
#endif
    int T;cin>>T;
    char str[10000];
    for(int qq = 1; qq <= T; qq++) {
        int ans = 0;
        int n;cin>>n;scanf("%s", str);
        int len = strlen(str), tot = str[0]-'0';;
        for(int i = 1; i < len; i++) {
            if( tot >= i ) {
                tot += str[i]-'0';
            }
            else {
                tot++ ,ans++;
                tot += str[i]-'0';
            }
        }
        printf("Case #%d: %d\n", qq, ans);
    }
	return 0;
}

