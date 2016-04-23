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

int M[1005];
int n, b;
LL count( LL time ) {
    LL ans = 0;
    for( int i=0;i<b;i++){
        ans += (time/(LL)M[i]);
        ans++;
    }
    return ans;
}
bool C(LL time, int num) {
    return count(time) >= (LL)num;
}
LL search(int num) {
        LL lb = 0, ub = 1e14;
        while(ub-lb>1LL) {
           LL  mid = (lb+ub)>>1;
           assert( lb <= mid && mid <= ub);
           if(C(mid, num)) ub = mid;
           else lb = mid;
        }
        return ub;
}
int main() {
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        cin>>b>>n;
        for(int i = 0; i < b; i++) scanf("%d", &M[i]);
        LL time = search(n);
        LL r = count(time);
        assert( r >= n);
        LL l = count(time-1);
        if( time -1 == 0) l = 0;
        vec tmp;assert(tmp.empty());
        for(int i =0;i<b;i++) if( (time%(LL)M[i]) == 0 ) tmp.pb(i);
        printf("Case #%d: %d\n", qq, tmp[n-l-1]+1);
    }
}

