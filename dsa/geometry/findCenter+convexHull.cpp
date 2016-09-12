#define REP(i,n) for ( int i=0; i<int(n); i++ )
int n;
void input() {
    scanf("%d",&n);
    REP(i,n) p[i].read();
}


P findCenter() {
    p[n]=p[0];
    P center=P{0,0};
    REP(i,n) {
        double v=p[i]*p[i+1];
        center.x += (p[i].x+p[i+1].x)*v;
        center.y += (p[i].y+p[i+1].y)*v;
    }
    double area=0;
    REP(i,n) area+=p[i]*p[i+1];
    area /= 2;
    center /= 6*area;
    return center;
}

P q1[N],q2[N],q[N];
void convex() {
    sort(p,p+n);
    int m1=0,m2=0;
    REP(i,n) {
        while ( m1>=2 && X(q1[m1-2],q1[m1-1],p[i]) >= 0 ) m1--;
        while ( m2>=2 && X(q2[m2-2],q2[m2-1],p[i]) <= 0 ) m2--;
        q1[m1++]=q2[m2++]=p[i];
    }
    int m=0;
    REP(i,m1) q[m++]=q1[i];
    for ( int i=m2-2; i>=1; i-- ) q[m++]=q2[i];
    q[m]=q[0];
}
void solve() {
    convex();
    // continue ...
}

