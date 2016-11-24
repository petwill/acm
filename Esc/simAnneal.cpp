//http://mikucode.blogspot.tw/2015/03/algorithm.html
//尋找和所有點距離和最小的點
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define F(n) Fi(i,n)
#define Fi(i,n) for(int i=0;i<n;i++)
#define N 1010
using namespace std;
int X[N],Y[N],n;
inline double pow2(double x){
    return x*x;
}
double check(double x,double y){
    double ans=0;
    F(n)ans+=sqrt(pow2(x-X[i])+pow2(y-Y[i]));
    return ans;
}
int main(){

    while(~scanf("%d",&n) ) {
        F(n) scanf("%d%d",X+i,Y+i);
        double x=0,y=0,tx,ty,tans,l=10000,ans;
        ans=check(x,y);
        while(l>1e-4) {
            int tmp=rand();
            tx=x+l*cos(tmp);ty=y+l*sin(tmp);
            tans=check(tx,ty);
            if(tans<ans) ans=tans,x=tx,y=ty;
            else l*=0.9;
        }
        printf("%.9f\n",2*ans);
    }
}

//尋找兩個點使他們跟給定的四個點最小生成樹最小
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define N 10
using namespace std;
int X[N],Y[N],n,F[N],e;
struct E{
    int a,b;
    double c;
}G[N*2];
struct V{
    double x,y;
    V operator+(double l){
        int tmp=rand();
        return (V){x+l*cos(tmp),y+l*sin(tmp)};
    }
}v[N];
int find(int x){
    return x==F[x]?x:F[x]=find(F[x]);
}
inline double pow2(double x){
    return x*x;
}
double check(V s1,V s2){
    double ans=0;
    e=0;v[4]=s1,v[5]=s2;
    F(5)Fl(j,i+1,6)
        G[e++]=(E){i,j,sqrt(pow2(v[i].x-v[j].x)+pow2(v[i].y-v[j].y))};
    F(6)F[i]=i;
    sort(G,G+e,[](E a,E b){return a.c<b.c;});
    F(e){
        if(find(G[i].a)!=find(G[i].b)){
            ans+=G[i].c;
            F[find(G[i].a)]=find(G[i].b);
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    while(n--){
        F(4) scanf("%lf%lf",&v[i].x,&v[i].y);
        double ttans,tans,ans,l1=10000,l2;
        V s1=(V){0,0},s2=(V){0,0},ts1,ts2,tmp;
        ans=check(s1,s2);
        while(l1>1e-3){
            l2=10000;
            ts1=s1+l1;
            tans=check(ts1,s2);
            tmp=s2;
            while(l2>1e-3){
                ts2=s2+l2;
                ttans=check(ts1,ts2);
                if(ttans<tans)tans=ttans,s2=ts2;
                else l2*=0.9;
            }
            if(tans<ans)ans=tans,s1=ts1;
            else l1*=0.9,s2=tmp;
        }
        printf("%f\n",2*ans);
    }
}
