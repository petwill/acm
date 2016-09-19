#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 100100
#define INF (1e9+5)

using namespace std;

int N,M,X[MAX_N];

bool judge(int d){
    int cnt = M - 1;
    //cnt cows not placed yet
    int last = 0,now = 1;
    while(now < N && cnt > 0){
        if(X[now] - X[last] >= d)
            last = now, cnt--;
        now++;
    }
    return cnt == 0;
}

/*
bool C(int d){
    int last = 0;
    for(int i = 1; i < M; i++){
        int crt = last + 1;
        while(crt < N && X[crt]-X[last] < d)
            crt++;
        if(crt == N) return false;
        last = crt;
    }
    return true;
}
*/
int main(){
    cin>>N>>M;
    for(int i = 0; i < N; i++)
        scanf("%d", &X[i]);
    sort(X, X+N);
    int ub = INF, lb = 0;
    while( ub - lb > 1 ) {
        int mid = (lb+ub)/2;
        if(judge(mid)) lb = mid;
        else ub = mid-1;
    }
    cout << ((judge(ub))?ub:lb) << endl;
    return 0;
}
