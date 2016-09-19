#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


long long mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    long long ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod) ret -= mod;
        }
    }
    return ret;
}

long long mpow2(long long x, long long y, long long mod) {
    long long ret = 1;
    while (y) {
        if (y&1)
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}
int isPrime(long long p, int it) { // implements by miller-babin
    if (p < 2)  return 0;
    if (p == 2) return 1;
    if (!(p&1)) return 0;
    long long q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))  q >>= 1, k++;

    while(it--) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }

    return 1;
}


int main() {

    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        long long n;
        scanf("%lld", &n);
        puts(isPrime(n, 1000)?"YES":"NO");
    }
    return 0;
}
