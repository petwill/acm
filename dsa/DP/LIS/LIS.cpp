#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#define MaxN 1000005
using namespace std;

int dp[MaxN],a[MaxN],n;

void solve(){
    fill(dp,dp+n,INT_MAX);
    for(int i=0;i<n;i++)
        *lower_bound(dp,dp+n,a[i])=a[i];

    for(int i=0;i<n;i++)
        printf("%d ", dp[i]);
    printf("\n%d\n", lower_bound(dp,dp+n,INT_MAX)-dp);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    solve();
}
