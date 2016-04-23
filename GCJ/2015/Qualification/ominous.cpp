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

int main() {
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        printf("Case #%d: ", qq);
        int x, r, c;scanf("%d%d%d", &x, &r, &c);
        //can't fill in the grid
        //printf("%d %d %d\n", x, r,c);
        if( max(r,c) < x || (r*c)%x!=0 || x >= 7|| (min(r,c) < (x+1)/2 )  ){puts("RICHARD");continue;}
        if(  x>=4 && min(r,c) == (x+1)/2) {
            if( x == 5) {
                if( max(r, c) == 5) {puts("RICHARD");continue;}
            }
            else { puts("RICHARD");continue; }
        }
        puts("GABRIEL");
    }
    return 0;
}
