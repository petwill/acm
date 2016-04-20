#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int adj[9][9], size[9]; // adjacency lists
int ref[9];            // �����ϤW�C�@���I�ثe���Q�h�ֱ���s��

void topological_ordering()
{
    for (int i=0; i<9; ++i) ref[i] = 0; // ��l�Ƭ�0

    // �֭p�ϤW�C�@���I�Q�X����s��
    for (int i=0; i<9; ++i)
        for (int j=0; j<size[i]; ++j)
            ref[adj[i][j]]++;

    // �ŧi�@��queue�Ӭ����w�g�S���Q������s�V���I

    //push a vertex with in-degree == 0
    queue<int> Q;
    for (int i=0; i<9; ++i)
        if (ref[i] == 0)
            Q.push(i);

    // �}�l��X�@�ӦX�z���ƦC����
    for (int i=0; i<9; ++i)
    {
        // �M��S���Q������s�V���I
        if (Q.empty()) break;       // �䤣��C��ܥثe�ݦs���ϬO�����C
        int s = Q.front(); Q.pop();
        ref[s] = -1;                // �]���w��L�]�R�hs�I�^

        cout << s;                  // �L�X�X�z���ƦC���Ǫ���i�I
                                    //���X�����ǧY���@�զX�z��

        // ��sref���ȡ]�R�h��s�I�s�X�h����^
        for (int j=0; j<size[s]; ++j)
        {
            int t = adj[s][j];
            ref[t]--;
            if (!ref[t]) Q.push(t); // �����w�g�S���Q������s�V���I
        }
    }
}
int main(){
    topological_ordering();
}

