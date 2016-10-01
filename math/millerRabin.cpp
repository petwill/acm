#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL mul(LL a, LL b, const LL mod) {
    LL x = 0,y = a % mod;
    while (b > 0) {
        if ( b&1 )
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b >>= 1;
    }
    return x % mod;
}
/*
LL mul(LL lhs, LL rhs, const LL mod ) {
    return ( lhs * rhs ) % mod;
}
*/
LL mypow(LL b, LL e,const LL mod) {
    LL x = 1;
    LL y = b;
    while ( e ) {
        if ( e&1 ) x = mul(x, y, mod);
        y = mul(y, y, mod);
        e >>= 1;
    }
    return x;
}
const int testbase[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool isprime(const LL p) {
    if (p < 2) return false;
    if (p != 2 && !(p&1) ) return false;
    LL d = p - 1;
    while ( !(d&1) ) d >>= 1;
    for( int a : testbase ) {

        LL td = d;
        if( a >= p-1 ) return true;
        LL st = mypow(a, td, p);
        while ( td != p - 1 && st != 1 && st != p - 1) {
            st = mul(st, st, p);
            td <<= 1;
        }
        if ( st != p - 1 && !(td&1) ) return false;
    }
    return true;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL q;
        scanf("%lld",&q);
        puts(isprime(q)?"YES":"NO");
    }
    return 0;
}
