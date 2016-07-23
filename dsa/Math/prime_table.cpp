#include <bits/stdc++.h>
using namespace std;
struct prime_table {

    int prime[1000000]={2,3,5,7};
    int sz=4;
    int ub=(1<<20);

    int check(int num){
        int k = 0;
        for(k = 0; k < sz && prime[k]*prime[k] <= num; k++){
            if( num % prime[k]==0)  return 0;
        }
        return 1;
    }

    void buildprime(){
        int currentPrime=7;
        int j=4;
        for(sz=4,j=4; currentPrime<ub; sz++, j=6-j){
             currentPrime=currentPrime+j;
             if (check(currentPrime)) {
                prime[sz] = currentPrime;
             }
             else{
                sz--;
             }
        }
     }
}p;
int main() {
    p.ub = (1<<20);
    p.buildprime();
    cout<< p.sz <<endl;
}
