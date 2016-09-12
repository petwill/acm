#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#define MaxN 1000005
using namespace std;

int dp[MaxN],a[MaxN],n;

int LIS(){
    fill(dp,dp+n,INT_MAX);
    for(int i=0;i<n;i++)
        *lower_bound(dp,dp+n,a[i])=a[i];
        //change it to upper_bound if solving longest non-decreasing sequence
    return ( lower_bound(dp,dp+n,INT_MAX) - dp ) ;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    cout << LIS() << endl;
}
