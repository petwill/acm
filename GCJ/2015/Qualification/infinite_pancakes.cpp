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
int arr[10005];
int main() {
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        int ans = inf;;
        int n;cin>>n;
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr+n);
        int cnt;
        for(int i=1;i<arr[n-1];i++) {
            cnt = i;
            for(int j=n-1;j>=0;j--){
                if( arr[j] < i) break;
                cnt += (arr[j]-1)/i;
            }
            ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", qq, min(arr[n-1],ans));
    }
	return 0;
}

