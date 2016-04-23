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
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        int n;cin>>n;int arr[1005];
        scanf("%d", &arr[0]);
        int ans1 = 0, ans2 = 0;
        int max_interval = 0;
        for(int i = 1; i < n; i++) {
            scanf("%d", &arr[i]);
            if( arr[i] < arr[i-1] ) {
                max_interval = max(max_interval, arr[i-1]-arr[i]);
                ans1 += (arr[i-1]-arr[i]) ;
            }
        }
        for(int i = 1; i < n; i++) ans2 += min(arr[i-1], max_interval);
        printf("Case #%d: %d %d\n", qq, ans1, ans2);
    }
}

