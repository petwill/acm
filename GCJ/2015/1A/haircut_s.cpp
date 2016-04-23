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
int M[1005];
LL lcm(int a, int b) {
    return ((LL)a*b)/(LL)__gcd(a,b);
}
int main() {
    int T;cin>>T;
    priority_queue< pii, vector<pii>, greater<pii> > que;
    for(int qq = 1; qq <= T; qq++) {
        while( !que.empty() ) que.pop();
        int b, n; cin>>b>>n;
        LL Lcm=1;
        for(int i = 0; i < b; i++)scanf("%d", &M[i]), Lcm = lcm(Lcm, M[i]), que.push(mp(0, i));;
        int tmp=0;
        for(int i =0 ; i < b; i++)tmp += Lcm/M[i];
        //cout << Lcm << endl;
        n %= tmp;
        n--;
        if( n == -1) {
            int ans=b-1 ;
            for(int i = b-1; i >=0; i--)
                if( M[i] < M[ans])  ans = i;
            printf("Case #%d: %d\n", qq , ans +1);
            continue;
        }
        while(   n--   ) {
            pii tp = que.top(); que.pop();
            tp.fi += M[tp.se];
            que.push( tp );
        }
        printf("Case #%d: %d\n", qq, que.top().se+1 );
    }
}

