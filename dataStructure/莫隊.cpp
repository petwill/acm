//區間眾數
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAXQ 1000000
struct Q{
    int l,r,i,block;
    inline bool operator<(const Q &b)const{
        return block==b.block?r<b.r:block<b.block;
    }
}q[MAXQ+5];
int s[MAXN+5],lim;
int ans1[MAXQ+5], ans2[MAXQ+5];
int u[MAXN+5],cnt[MAXN+5],cur_ans;
inline void add(int x){
    x=++u[x];
    --cnt[x-1];
    ++cnt[x];
    cur_ans=max(cur_ans,x);
}
inline void sub(int x){
    x=--u[x];
    --cnt[x+1];
    ++cnt[x];
    if(!cnt[cur_ans])--cur_ans;
}
int n,m;
int p[MAXN+5],nn;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&s[i]);
        p[i-1]=s[i];
    }
    sort(p,p+n);
    nn=unique(p,p+n)-p;
    for(int i=1;i<=n;++i)s[i]=lower_bound(p,p+nn,s[i])-p;
    lim=1+(int)sqrt(n);
    for(int i=0;i<m;++i){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].block=q[i].l/lim;
        q[i].i=i;
    }
    sort(q,q+m);
    for(int i=0,L=1,R=0;i<m;++i){/*這是閉區間的寫法*/
        while(R<q[i].r)add(s[++R]);
        while(R>q[i].r)sub(s[R--]);
        while(L>q[i].l)add(s[--L]);
        while(L<q[i].l)sub(s[L++]);
        ans1[q[i].i]=cur_ans;
        ans2[q[i].i]=cnt[cur_ans];
    }
    for(int i=0;i<m;++i)printf("%d %d\n",ans1[i], ans2[i]);
    return 0;
}
