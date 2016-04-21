#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int DAT_SIZE = (1 << 18) - 1;

int N, Q;
long long data[DAT_SIZE], datb[DAT_SIZE];

void add(int L, int R, int k, int a, int b, int x){
    if(a >= L && b <= R)
        data[k] += x;
    else if( a < R && L < b) {
        datb[k] += (min(R, b) - max(L, a)) * x;
        add(L, R, 2*k+1, a, (a+b)/2, x);
        add(L, R, 2*k+2, (a+b)/2, b, x);
    }
}
LL sum(int L, int R, int k, int a, int b){
    if(a >= L && b <= R)
        return data[k]*(b-a) + datb[k];
    if(R <= a || L >= b)
        return 0;
    LL res = (min(R, b) - max(L, a)) * data[k];
    res += sum(L, R, 2*k+1, a, (a+b)/2);
    res += sum(L, R, 2*k+2, (a+b)/2, b);
    return res;
}
int main(){
    cin>>N>>Q;
    for(int i = 0; i < N; i++){
        int a;scanf("%d", &a);
        add(i, i+1, 0, 0, N, a);
    }
    while(Q--){
        char tmp[2];scanf("%s", tmp);
        int L, R, x;
        if(tmp[0]=='Q'){
            scanf("%d%d", &L, &R);
            printf("%lld\n", sum(L-1, R, 0, 0, N));
        }else {
            scanf("%d%d%d" ,&L, &R, &x);
            add(L-1, R, 0, 0, N, x);
        }
    }
    return 0;
}
