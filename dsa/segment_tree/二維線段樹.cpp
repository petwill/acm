///POJ 2155
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1005

using namespace std;

bool tree[maxn<<2][maxn<<2];
int n,ans;

void buildy(int num,int s,int e,int rt)
{
    tree[rt][num]=0;
    if(s==e)return;
    int mid=(s+e)>>1;
    buildy(num<<1, s, mid, rt);
    buildy(num<<1|1, mid+1, e, rt);
}

void buildx(int num,int s,int e)
{
    buildy(1,1,n,num);
    if(s==e)return;
    int mid=(s+e)>>1;
    buildx(num<<1, s, mid);
    buildx(num<<1|1, mid+1, e);
}

void updatey(int num,int s,int e,int l,int r,int rt)
{
    if(l<=s && r>=e)
    {
        tree[rt][num]^=1;
        return ;
    }
    int mid=(s+e)>>1;
    if(r>mid)updatey(num<<1|1, mid+1, e,l,r,rt);
    if(l<=mid)updatey(num<<1, s, mid,l,r,rt);
}

void updatex(int num,int s,int e,int l,int r,int u,int d)
{
    if(l<=s && r>=e)
    {
        updatey(1,1,n,u,d,num);
        return;
    }
    int mid=(s+e)>>1;
    if(r>mid)
    updatex(num<<1|1, mid+1, e,l,r,u,d);
    if(l<=mid)
    updatex(num<<1, s, mid,l,r,u,d);
}

void queryy(int num,int s,int e,int y,int rt)
{
    ans^=tree[rt][num];
    if(s==e)return;
    int mid=(s+e)>>1;
    if(y<=mid)queryy(num<<1, s, mid,y,rt);
    else if(y>mid)queryy(num<<1|1, mid+1, e,y,rt);
}

void queryx(int num,int s,int e,int x,int y)
{
    queryy(1,1,n,y,num);
    if(s==e) return;
    int mid=(s+e)>>1;
    if(x>mid)queryx(num<<1|1, mid+1, e,x,y);
    else if(x<=mid)queryx(num<<1, s, mid,x,y);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int op;
        scanf("%d%d",&n,&op);
        buildx(1,1,n);
        while(op--){
            char p[10];
            scanf("%s",p);
            if(p[0]=='C'){
                int x1,x2,y1,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                updatex(1,1,n,x1,x2,y1,y2);
            }
            else{
                int a,b;
                scanf("%d%d",&a,&b);
                ans=0;
                queryx(1,1,n,a,b);
                printf("%d\n",ans);
            }
        }
        puts("");
    }
    return 0;
}
