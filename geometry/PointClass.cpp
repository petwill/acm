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
