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
int r, c, n;
int table[10002][10002];
void print() {
        puts("");
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++)
                printf("%d ", table[i][j]);
            putchar('\n');
        }
}
int  main() {
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        printf("Case #%d: ", qq);
        cin>>r>>c>>n;
        //printf("r = %d, c = %d %d\n", r, c, n);
        if( n <= (r*c+1)/2 ) {puts("0");continue;}
        int erase = r*c-n;
        int ans = (r-1)*c + (c-1)*r;
        //memset(table, 0, sizeof(table));
        for(int i = 2; i <= r; i++) {
           for(int j = 2; j <= c; j++) {
              table[i][j] = 4;
            }
        }
        for(int i = 1; i <= r; i++) table[i][1] = table[i][c] = 3;
        for(int i = 1; i <= c; i++) table[1][i] = table[r][i] = 3;
        table[1][c] = table[1][1] = table[r][c] = table[r][1] = 2;
        if( r == 1 || c == 1 ) for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) table[i][j]--;

        //print();
        while( erase-- ) {
            int M = 0, R, C;
            for(int i = 1; i <= r; i++) {
                for(int j =1;j <=c; j++) {
                    if( table[i][j] >= 1) {
                        if( table[i][j] > M) M = table[i][j], R = i, C = j;
                    }
                }
            }
            if( M == 0) break;
            assert( table[R][C] >= 1);

            ans -= table[R][C];
            table[R][C]  =-1;
            table[R-1][C]--, table[R+1][C]--, table[R][C-1]--, table[R][C+1]--;
           // print();
        }
        printf("%d\n", ans);
    }
	return 0;
}


