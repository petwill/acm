#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;
#define N 100
struct P {
    double x, y;
    P(double _x=0, double _y=0) :x(_x), y(_y) {};
    void read() {
        scanf("%lf%lf",&x,&y);
    }
    void print() {
        printf("%f %f\n", x, y);
    }
} p[N];
#define double double
bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
P operator +( P a, P b ) { return P{a.x+b.x,a.y+b.y}; }
P operator -( P a, P b ) { return P{a.x-b.x,a.y-b.y}; }
P operator *(  P b, double a ) { return P{a*b.x,a*b.y}; }
P operator /( P a, double b ) { return P{a.x/b,a.y/b}; }
P& operator /=( P &a, double b ) { return a=a/b; }
double operator *( P a, P b ) { return a.x*b.x+a.y*b.y; }
double operator ^( P a, P b ) { return a.x*b.y-a.y*b.x; }
double x( P o, P a, P b ) { return (a-o)^(b-o); }
double dot( P o, P a, P b ) { return (a-o)*(b-o); }

vector<P> interCircle( P o1 , double r1 , P o2 , double r2 ){
  double d2 = ( o1 - o2 ) * ( o1 - o2 );
  double d = sqrt(d2);
	if( d > r1 + r2 ) return {};
  P u = (o1+o2)*0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  double A = sqrt((r1+r2+d)*(r1-r2+d)*(r1+r2-d)*(-r1+r2+d));
  P v = P( o1.y-o2.y , -o1.x + o2.x ) * A / (2*d2);
  return {u+v, u-v};
}

