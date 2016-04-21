#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 1e18
using namespace std;

int n, m, a, b;
int t[10], d[40][40];
double dp[1024][40];

int main(){
    int p;
    while(cin>>n>>m>>p>>a>>b){
        if(n+m+p+a+b == 0) return 0;
        memset(d, -1, sizeof(d));
        for(int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        while(p--){
            int A,B,C;
            scanf("%d%d%d" ,&A, &B, &C);
            d[A-1][B-1] = d[B-1][A-1] = C;
        }
        for(int i = 0; i < (1<<n); i++)
            fill(dp[i], dp[i]+m, INF);
        dp[(1<<n)-1][a-1] = 0;
        double res = INF;
        for(int s = (1<<n)-1; s >= 0; s--){
            res = min(res, dp[s][b-1]);
            for(int u = 0; u < m; u++){
                for(int i = 0; i < n; i++){
                    if(s >> i & 1){
                        for(int v = 0; v < m; v++){
                            if(d[u][v] >= 0) {
                                dp[s-(1<<i)][v] = min(dp[s-(1<<i)][v], dp[s][u] + (double)d[u][v]/t[i]);
                            }
                        }
                    }
                }
            }
        }
        if(res != INF)printf("%.3f\n" ,res);
        else cout << "Impossible" << endl;
    }
}
