#include <bits/stdc++.h>
using namespace std;
int  num[100000],L[100000];
int num_len,i,j;
int previous[10000];
int longest;
void trace(int i) {
    if (previous[i] != -1)trace(previous[i]);
    cout << num[i] << ' ';
}

int main(){
    int T;cin>>T;
    while(T--){
        ///initialize
        longest = 0;
        int longest_index = 0;
        memset(previous, -1, sizeof(previous));
        ///input
        cin>>num_len;
        for(i = 0; i < num_len; i++)
            scanf("%d" ,&num[i]);
        ///start LIS
        for (i = 0; i < num_len; i++){
            // answer for LIS terminated in num[i]
            L[i] = 1;
            for (j = 0; j < i; j++){
               if (num[j] < num[i] && L[i] < L[j] + 1){
                   L[i] = L[j] + 1;
                    ///record previous
                   previous[i] = j;
               }
            }
        }
        for(int i=0;i<num_len;i++){
            if (L[i] > longest){
                longest = L[i];
                longest_index = i;
            }
        }
        printf("%d\n" ,longest);
        trace(longest_index);
        puts("");
    }
    return 0;
}
