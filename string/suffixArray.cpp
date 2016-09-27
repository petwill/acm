#include <bits/stdc++.h>
using namespace std;
/** Suffix Array **/
struct SuffixArray{
    /**
     DA(倍增)算法求 SA[N] 与 Rank[N] （时间O(NlogN）,空间O(N)）
    sa[i] : 表示 排在第i位的后缀 起始下标 , sa[ 0 .. n ] ==> sa[0] = n 是空字串
                                             consider sa[ 1 .. n ] stores [ 0 .. n )
    Rank[i] : 表示后缀 suffix(i)排在第几, Rank[ 0 .. n ] ==> Rank[n] = 0 空字串
                                             consider ==> Rank[ 0 .. n ) stores [ 1 .. n ]

    lcp[i] : 表示 suffix ( sa[i-1] ) 与 suffix ( sa[i] ) 的LCP 值, lcp[ 1 .. n ], lcp[1] = 0 (與空字串比較)
    h[i]: 表示 suffix(i)与其排名前一位的 LCP值, h[ 0 .. n )
    LCP : longest common prefix

    **/
    #define N 100005
    int cmp(int *r,int a,int b,int l){
        return (r[a]==r[b]) && (r[a+l]==r[b+l]);
    }
    // 用于比较第一关键字与第二关键字,
    // 比较特殊的地方是,预处理的时候,r[n]=0(小于前面出现过的字符)
    int wa[N],wb[N],ws[N],wv[N];
    int r[N], sa[N];
    int Rank[N], lcp[N];
    void DA(int n,int m){ //此处n比输入的n要多1，为人工添加的一个字符，用于避免CMP时越界
        int *x=wa,*y=wb;
        for(int i=0;i<m;i++) ws[i]=0;
        for(int i=0;i<n;i++) ws[x[i]=r[i]]++;
        for(int i=1;i<m;i++) ws[i]+=ws[i-1];
        for(int i=n-1;i>=0;i--) sa[--ws[x[i]]] = i;
        for(int j=1,p; p<n;j*=2,m=p) {
            p = 0;
            for(int i=n-j;i<n;i++) y[p++]=i;
            for(int i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(int i=0;i<m;i++) ws[i]=0;
            for(int i=0;i<n;i++) wv[i]=x[y[i]];
            for(int i=0;i<n;i++) ws[wv[i]]++;
            for(int i=1;i<m;i++) ws[i]+=ws[i-1];
            for(int i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
            swap(x, y), p = 1, x[ sa[0] ] = 0;
            for(int i=1;i<n;i++)
                x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
    void calcLcp(int n){ // 此处N为实际长度
        int i,j,k=0;        // height[]的合法范围为 1-N, 其中0是结尾加入的字符
        for(i=1;i<=n;i++) Rank[sa[i]]=i;  // 根据SA求Rank
        for(i=0;i<n; lcp[Rank[i++]] = k ) // 定义：h[i] = height[ Rank[i] ]
        for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++); //根据 h[i] >= h[i-1]-1 来优化计算height过程
    }
    void init(char *s, int len) {
        for(int i = 0; i < len; i++) r[i] = (int)s[i];
        r[len] = 0;
    }
}sa;

char str[N];
int main() {
    scanf("%s",str);
    int n = strlen(str);

    sa.init(str, n);
    sa.DA(n+1,128);  //注意区分此处为n+1,因为添加了一个结尾字符用于区别比较
    sa.calcLcp(n);
    /** demonstrate
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
    **/
}

