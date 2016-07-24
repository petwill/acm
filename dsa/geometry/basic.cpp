#include <bits/stdc++.h>
using namespace std;

/** 
const double EPS = 1e-10;
struct P {
    double x,y;
    void read() {
        scanf("%lf%lf",&x,&y);
    }
    void print() {
        printf("%f %f\n", x, y);
    }
} p[N];
bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
P operator +( P a, P b ) { return P{a.x+b.x,a.y+b.y}; }
P operator -( P a, P b ) { return P{a.x-b.x,a.y-b.y}; }
P operator *( double a, P b ) { return P{a*b.x,a*b.y}; }
P operator /( P a, double b ) { return P{a.x/b,a.y/b}; }
P& operator /=( P &a, double b ) { return a=a/b; }
double operator *( P a, P b ) { return a.x*b.y-a.y*b.x; }
double X( P o, P a, P b ) { return (a-o)*(b-o); }
double dot( P a, P b ) { return a.x*b.x+a.y*b.y; }
double dot( P o, P a, P b ) { return dot(a-o,b-o); }
**/

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
