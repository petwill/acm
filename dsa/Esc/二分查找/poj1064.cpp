//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>


using namespace std;

int N,K;
double L[10005];

bool C(double x){
    int num = 0;
    for(int i = 0; i < N; i++){
        num += (int)(L[i]/x) ;
    }
    return num >= K ;
}

int main(){
    cin>>N>>K;
    for(int i = 0; i < N; i++)
        scanf("%lf", &L[i]);
    double lb = 0, ub = 100100;

    int LOOP = 100;
    while(ub-lb > 1e-5){
        double mid = (lb+ub)/2;
        if(C(mid)) lb = mid;
        else ub = mid;
    }
    printf("%.2f\n", floor(ub*100)/100);
    return 0;
}
