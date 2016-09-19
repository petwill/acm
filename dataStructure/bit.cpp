#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
int n, a[100005];

int bit[100005];
//bit stands for binary indexed tree
int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}
void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += i & -i;
    }
}

//給定1~n的排列
//泡沫排序的交換次數
void solve(){
    LL ans = 0;
    for(int j = 0; j < n; j++){
        ans += j - sum(a[j]);
        add(a[j], 1);
    }
    printf("%lld\n" ,ans);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    solve();
    puts("check");
    for(int i = 0; i <= n; i++)
        printf("%d ", bit[i]);
}
