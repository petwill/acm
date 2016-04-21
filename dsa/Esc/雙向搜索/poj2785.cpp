#include <algorithm>
#include <cstdio>
#include <iostream>
#define Max_N 4005

using namespace std;

int A[Max_N], B[Max_N], C[Max_N], D[Max_N];
int N;
int CD[Max_N*Max_N];

int main(){
    cin>>N;
    for(int i = 0; i < N; i++)
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            CD[i*N+j] = C[i] + D[j];
        }
    }
    sort(CD , CD+N*N);
    long long res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int cd = -(A[i]+B[j]);
            res += upper_bound(CD, CD+N*N, cd) - lower_bound(CD, CD+N*N, cd);
        }
    }
    cout << res << endl;
}
