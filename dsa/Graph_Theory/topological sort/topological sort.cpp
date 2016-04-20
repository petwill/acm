#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int adj[9][9], size[9]; // adjacency lists
int ref[9];            // 紀錄圖上每一個點目前仍被多少條邊連到

void topological_ordering()
{
    for (int i=0; i<9; ++i) ref[i] = 0; // 初始化為0

    // 累計圖上每一個點被幾條邊連到
    for (int i=0; i<9; ++i)
        for (int j=0; j<size[i]; ++j)
            ref[adj[i][j]]++;

    // 宣告一個queue來紀錄已經沒有被任何邊連向的點

    //push a vertex with in-degree == 0
    queue<int> Q;
    for (int i=0; i<9; ++i)
        if (ref[i] == 0)
            Q.push(i);

    // 開始找出一個合理的排列順序
    for (int i=0; i<9; ++i)
    {
        // 尋找沒有被任何邊連向的點
        if (Q.empty()) break;       // 找不到。表示目前殘存的圖是個環。
        int s = Q.front(); Q.pop();
        ref[s] = -1;                // 設為已找過（刪去s點）

        cout << s;                  // 印出合理的排列順序的第i點
                                    //取出的順序即為一組合理解

        // 更新ref的值（刪去由s點連出去的邊）
        for (int j=0; j<size[s]; ++j)
        {
            int t = adj[s][j];
            ref[t]--;
            if (!ref[t]) Q.push(t); // 紀錄已經沒有被任何邊連向的點
        }
    }
}
int main(){
    topological_ordering();
}

