#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;

double operator +(double a, double b) {
    if( abs(a+b) < EPS*(abs(a)+abs(b)) ) return 0;
    return a+b;
}

template <typename T>
struct P{
    T x, y;
    P(T _x = 0,T  _y = 0): x(_x), y(_y){}
    P operator + (P p) { return P(x+p.x, y+p.y); }
    P operator - (P p) { return P(x-p.x, y-p.y); }
    T dot(P p) { return x*p.x + y*p.y; }
    T det(P p) { return x*p.y - y*p.x; }
};

int main() {
    P<double> a(1.4, 5.6), b(3, 4);
    a.x = a.dot(b);
    cout << a.x << " " << a.y << endl;
    return 0;
}
