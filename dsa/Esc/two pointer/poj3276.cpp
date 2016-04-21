#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define Max_N 5050
using namespace std;

int N, dir[Max_N], f[Max_N];

int calc(int k){
    int res = 0;
    int sum = 0;
    memset(f, 0, sizeof(f));
    for(int i = 0; i+k <= N; i++){
        // odd number => BACK
        if((dir[i]+sum)%2)
            f[i] = 1, res++;
        sum += f[i];
        if(i+1-k >= 0) sum -= f[i+1-k];
    }
    for(int i = N+1-k; i < N; i++)
        if((dir[i]+sum)%2) return -1;
        else {
            if(i+1-k>=0) sum -= f[i+1-k];
        }
    return res;
}

int main(){
    cin>>N;
    for(int i = 0; i < N; i++){
        char tmp[2];scanf("%s", tmp);
        dir[i] = (tmp[0]=='B')? 1:0;
    }

    int M = N, K = 1;
    for(int k = 1; k <= N; k++){
        int m = calc(k);
        if(m >= 0 && M > m)
            M = m, K = k;
    }
    printf("%d %d\n", K, M);
}
