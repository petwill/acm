//http://www.cnblogs.com/yefeng1627/p/3233611.html
/** template **/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
// including iostream can't compile !??
//#include <iostream>
using namespace std;
/**
DA(倍增)算法求 SA[N] 与 Rank[N] （时间O(NlogN）,空间O(N)）

sa[i] : 表示 排在第i位的后缀 起始下标
Rank[i] : 表示后缀 suffix(i)排在第几
height[i] : 表示 suffix ( sa[i-1] ) 与 suffix ( sa[i] ) 的LCP 值
h[i]: 表示 suffix(i)与其排名前一位的 LCP值 => not included in template
LCP : longest common prefix
**/

const int N = 5*10001;
int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
// 用于比较第一关键字与第二关键字,
// 比较特殊的地方是,预处理的时候,r[n]=0(小于前面出现过的字符)

int wa[N],wb[N],ws[N],wv[N];
int Rank[N],height[N];
void DA(int *r,int *sa,int n,int m){ //此处N比输入的N要多1，为人工添加的一个字符，用于避免CMP时越界
    int i,j,p,*x=wa,*y=wb;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]] = i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

void calheight(int *r,int *sa,int n){ // 此处N为实际长度
    int i,j,k=0;        // height[]的合法范围为 1-N, 其中0是结尾加入的字符
    for(i=1;i<=n;i++) Rank[sa[i]]=i;  // 根据SA求Rank
    for(i=0;i<n; height[Rank[i++]] = k ) // 定义：h[i] = height[ Rank[i] ]
    for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++); //根据 h[i] >= h[i-1]-1 来优化计算height过程
}

char str[N];
int sa[N], r[N];
int main() {
    scanf("%s",str);
    int n = strlen(str);
    for(int i = 0;i < n; i++)
        r[i] = (int)str[i];
    r[n]=0;
    DA(r,sa,n+1,128);  //注意区分此处为n+1,因为添加了一个结尾字符用于区别比较
    calheight(r,sa,n);


//    /** demonstrate
    assert(sa[0] == n);
    for(int i = 0; i <= n; i++) printf("%d ", sa[i]);
    printf("\n");
    assert(Rank[n] == 0);
    for(int i = 0; i <= n; i++) printf("%d ", Rank[i]);
    printf("\n");
    //height[0] 沒有意義
    assert(height[1] == 0); //since sa[0] is 空字串
    printf("  ");
    for(int i = 1; i <= n; i++) printf("%d ", height[i]);
    printf("\n");
//    **/
}

