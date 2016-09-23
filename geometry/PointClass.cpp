const double eps = 1e-10;
#define N 100
struct P {
    type x,y;
    void read() {
        scanf("%lf%lf",&x,&y);
    }
    void print() {
        printf("%f %f\n", x, y);
    }
} p[N];
#define type double
bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
P operator +( P a, P b ) { return P{a.x+b.x,a.y+b.y}; }
P operator -( P a, P b ) { return P{a.x-b.x,a.y-b.y}; }
P operator *(  P b, type a ) { return P{a*b.x,a*b.y}; }
P operator /( P a, type b ) { return P{a.x/b,a.y/b}; }
P& operator /=( P &a, type b ) { return a=a/b; }
type operator *( P a, P b ) { return a.x*b.x+a.y*b.y; }
type operator ^( P a, P b ) { return a.x*b.y-a.y*b.x; }
type X( P o, P a, P b ) { return (a-o)^(b-o); }
type dot( P o, P a, P b ) { return (a-o)*(b-o); }

