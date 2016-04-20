#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10000
int parent[MAX],rank[MAX];//父親,樹的高度
int n,k,cnt;
/*
int find(int r){
    int p=r;
    while(p!=parent[p]) p=parent[p];
    int temp;
    while(r!=p)
        temp=parent[r],parent[r]=p,r=temp;
    return p;
}
*/
int find(int x){
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}

void unionn(int r1,int r2){

    r1=find(r1),r2=find(r2);

    if(rank[r1]<rank[r2])
        parent[r1]=r2;
    else{
        parent[r2]=r1;
        if(rank[r1]==rank[r2])
            rank[r1]++;//因爲r2的父節點變成了r1，深度+1
    }
}

bool same(int a,int b){
 return find(a)==find(b); //相等表示同一個集合
}

int main(){
    while(~scanf("%d%d",&n,&k)){
        cnt=0;
        for(int i=0;i<=3*n;i++)//這裏賦值到3*n,一開始沒注意到，然後結果也不對
            parent[i]=i;

    memset(rank,0,sizeof(rank));
    for(int i=0;i<k;i++){
        int d,r1,r2;
        scanf("%d%d%d",&d,&r1,&r2);
        if(r1>n||r2>n)
        { cnt++;continue; }
        /**以下要做的，就是r1表示A種類，r1+n表示B，r1+2*n表示C ，r2同理。**/
        if(d==1){//同類
            if( same(r1,r2+n) || same(r1,r2+2*n) )
               /*這裏是處理同類的2種情況，
                 假如r1（A種類）和r2（B種類）是同一個集合，那麽這肯定是假話
                 假如r1(A種類)和r2(C種類)是同一個集合，也是假話
               */
                cnt++;
            else{
                unionn(r1,r2);
                unionn(r1+n,r2+n);
                unionn(r1+2*n,r2+2*n);
            }
                /*假如是真話，它們就是同類，分別合成一個集合,A與A，B與B，C與C */
        }
        else{//x吃y
            if(same(r1,r2)||same(r1,r2+2*n) )
                 /*這裏是處理x吃y的2種情況，
                 假如r1（A種類）和r2（A種類）是同一個集合，不能同類相吃 ，是假話
                 假如r1(A種類)和r2(C種類)是同一個集合，也是假話 ，只有C種類吃A種類，A種類只能吃B種類。
               */
                cnt++;
            else{
                unionn(r1,r2+n);
                unionn(r1+n,r2+2*n);
                unionn(r1+2*n,r2);
            }
           /*假如是真話，那麽就讓x吃y的關系合成一個集合,A種類吃B，B吃C，C吃A */
        }
    }
    printf("%d\n",cnt);
    }
    return 0;
}
