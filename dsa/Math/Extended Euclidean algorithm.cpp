#include <cstdio>

using namespace std;

/** normal gcd function using recursion **/
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else {
        x = 1, y = 0;
    }
    return d;
}
int main(){
    printf("Find solution of ax + by = gcd(a, b)\n");
    int a,b,x,y;
    scanf("%d%d", &a, &b);
    extgcd(a, b, x, y);
    printf("%d %d\n" ,x, y);
    return 0;
}
