#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
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
    for(int qq = 1; qq <= T; qq++) {
        printf("Case #%d: ", qq);
        char n[105]; scanf("%s", n);
        int last = strlen(n)-1;
        int ans = 0, head = 0;
        int flag = 1;char toggle = 0;
        while( head != last ) {
            if( (toggle^n[last]) == '-') {
                if( (toggle^n[head] )!= '-' ) ans++;
                toggle ^= ('+'^'-');
                swap(head, last);
                last += (head-last)/abs(head-last);
                ans++;
            }
            if( head != last)
                last += (head-last)/abs(head-last);
       }
       cout << ans + ((toggle^n[last]) == '-') << endl;
    }
	return 0;
}
