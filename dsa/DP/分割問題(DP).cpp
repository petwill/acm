#include <cstdio>
#include <iostream>
#include <cstring>
#define MaxN 1005
using namespace std;
int M,n,m;
int dp[MaxN+1][MaxN+1];
/** if 0 is not allowed

    if(j-i>=0)
        dp[i][j] = dp[i-1][j-1]+dp[i][j-i];
    else
        dp[i][j] = dp[i-1][j-1];

**/
void solve(){
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j-i>=0)
                dp[i][j] = dp[i-1][j]+dp[i][j-i];
            else
                dp[i][j] = dp[i-1][j];
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            printf("%d%c", dp[i][j], (j==n)?'\n':' ');

}
int main(){
    scanf("%d%d%d", &n, &m, &M);
    memset(dp, 0, sizeof(dp));
    solve();
    printf("%d\n", dp[m][n]);
}
