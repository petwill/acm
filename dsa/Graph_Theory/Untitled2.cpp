#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
#define INF 0x7fffffff
#define LL long long
const int maxn = 1000 + 10;

struct node{ int x, y, time; };                            //点结构体
int g[maxn][maxn];                                         //图
int dir[5][2] = {0, 0, 0, 1, 0, -1, 1, 0, -1, 0};          //方向数组

int bfs(){
    if(g[0][0] == 0) return -1;                            //从（0，0）开始搜
    if(g[0][0] == -1) return 0;                            //起点安全，不用躲了
    node tmp, now;
    tmp.x = tmp.y = tmp.time = 0;
    queue<node> q;
    q.push(tmp);
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i=0; i<5; i++){
            tmp.x = now.x + dir[i][0], tmp.y = now.y + dir[i][1];
            tmp.time = now.time + 1;
            if(tmp.x < 0 || tmp.y < 0) continue;
            if(g[ tmp.x ][ tmp.y ] == -1) return tmp.time;
            if(tmp.time >= g[ tmp.x ][ tmp.y ]) continue;
            g[ tmp.x ][ tmp.y ] = tmp.time;
            q.push(tmp);
        }
    }
    return -1;
}

int main(){


    int n, x, y, d;
    while(scanf("%d", &n)!=EOF){
        memset(g, -1, sizeof(g));
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &x, &y, &d);
            for(int j=0; j<5; j++){                                //预处理
                int dx = x + dir[j][0], dy = y + dir[j][1];
                if(dx < 0  || dy < 0 ) continue;
                g[dx][dy] = g[dx][dy] == -1 ? d : min(g[dx][dy], d);
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}
