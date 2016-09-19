//http://codeforces.com/gym/100153/attachments
// 找函數cost 的極值
#include <cstdio>
using namespace std;
int p[100], q[100], s[100];

double cost(int n, int a, int b, double m) {
    double sum = b * m;
    for(int i = 0; i < n; i++)
        if(s[i] * m < p[i])
            sum += (p[i] - s[i] * m) / q[i] * a;
    return sum;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("academy.in",  "r", stdin);
    freopen("academy.out", "w", stdout);
#endif
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", p + i, q + i, s + i);
    double l = 0.0, r = 1000.0;
    for(int i = 0; i < 1000; i++) {
        double m1 = (l * 2 + r) / 3;
        double m2 = (l + r * 2) / 3;
        double vm1 = cost(n, a, b, m1);
        double vm2 = cost(n, a, b, m2);

        if(vm1 < vm2)
            r = m2;
        else
            l = m1;
    }
    double g = (l + r) / 2;
    printf("%.99f\n", cost(n, a, b, g));
    printf("%.99f\n", g);
    for(int i = 0; i < n; i++) {
        double x = (p[i] - s[i] * g) / q[i];
        if(x < 0)
            x = 0;
        printf("%.99f%c", x, i == n - 1 ? '\n' : ' ');
    }
}
