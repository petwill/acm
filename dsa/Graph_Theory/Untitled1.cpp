#include <bits/stdc++.h>
using namespace std;
class t {
public:
    int a[10];
    pair<int,int> pa;
};
int main() {
    vector<int> a(10); a[0] = -1;
    vector<int> b, c = a;
    b = a;
    a[0] = -2;
    printf("%d %d\n",(int)b.size(), b[0]);
    printf("%d %d\n",(int)c.size(), c[0]);
//    cout << a << endl;
//    printf("%d, %d\n", a.size(), a[0]);
    system("pause");
    t A, B;
    pair<int, int> r(1, 2),  m;
    m = r;
    printf("%d %d\n", m.first, m.second);
    A.a[0] = 10; A.pa.first = 1, A.pa.second = 2;
    B = A;
    printf("%d", B.a[0]);
}
