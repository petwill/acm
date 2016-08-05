//http://acm.csie.org/ntujudge/problemdata/2575.pdf
//http://www.csie.ntnu.edu.tw/~u91029/Half-planeIntersection.html

/**
預先使用四個半平面，設定一個極大的正方形邊界，讓半平面交集擁有邊界。
二、逐一加入每個半平面，求出當下的半平面交集（凸多邊形）。
online 演算法，隨時維護一個半平面交集。每次更新需時 O(N) ，總時間複雜度為 O(N^2) ， N 是半平面數目。
**/

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

typedef complex<double> Point;
typedef vector<Point> Polygon;
typedef pair<Point,Point> Line;
#define x real()
#define y imag()

// 兩向量叉積
double cross(Point& a, Point& b)
{
    return a.x * b.y - a.y * b.x;
}

// 向量oa與向量ob進行叉積
double cross(Point& o, Point& a, Point& b)
{
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

// 多邊形面積
double area(Polygon& p)
{
    double a = 0;
    int n = p.size();
    for (int i=0; i<n; ++i)
        a += cross(p[i], p[(i+1)%n]);
    return fabs(a) / 2;
}

// 兩線交點
Point intersection(Point& a1, Point& a2, Point& b1, Point& b2)
{
    Point a = a2 - a1, b = b2 - b1, s = b1 - a1;
    return a1 + a * cross(b, s) / cross(b, a);
}

// 一個凸多邊形與一個半平面的交集
Polygon halfplane_intersection(Polygon& p, Line& line)
{
    Polygon q;
    Point p1 = line.first, p2 = line.second;

    // 依序窮舉凸多邊形所有點，判斷是否在半平面上。
    // 如果凸多邊形與半平面分界線有相交，就求交點。
    int n = p.size();
    for (int i=0; i<n; ++i)
    {
        double c = cross(p1, p2, p[i]);
        double d = cross(p1, p2, p[(i+1)%n]);
        if (c >= 0) q.push_back(p[i]);
        if (c * d < 0) q.push_back(intersection(p1, p2, p[i], p[(i+1)%n]));
    }
    return q;
}
#define maxn 550
//Line line[maxn];
Point v[maxn];
double ans[maxn];
int main() {
    int T;cin>>T;
    while(T--) {
        int n;
        double  w, h;
        scanf("%d %lf %lf", &n, &w, &h);
        // 預先設定一個極大的正方形邊界
        Polygon p, org;
        /** initialize
         p.push_back(Point(-1e9,-1e9));
        p.push_back(Point(-1e9,+1e9));
        p.push_back(Point(+1e9,-1e9));
        p.push_back(Point(+1e9,+1e9));
        **/
        p.push_back(Point(0,0));
        p.push_back(Point(0,h));
        p.push_back(Point(w,h));
        p.push_back(Point(w,0));
        org = p;
        for(int i =0;i < n;i ++) {
            double a, b;
            scanf("%lf %lf", &a, &b);
            v[i] = Point(a, b);
        }
        // 每一個半平面都與目前的半平面交集求交集
        for (int i=0; i<n; ++i)
        {
            p = org;
            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                Line line;
                // find perpendicular line to line i_j
                Point a( (v[i].x+v[j].x)/2, (v[i].y+v[j].y)/2 );
                Point b(a.x+(v[i].y-v[j].y), a.y-(v[i].x-v[j].x));

                line = cross(a, b, v[i]) >=0 ? mp(a, b): mp(b,a);
                p = halfplane_intersection(p, line);
                if (area(p) == 0) break;    // 退化或者空集合
            }
            ans[i] = area(p);
        }
        for(int i = 0;i < n;i ++) printf("%.9f\n", ans[i]);
    }
}
/*
10
3 4 4
1 1 2 2 3 3
*/
