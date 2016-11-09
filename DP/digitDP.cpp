/**
简介
顾名思义，所谓的数位DP就是按照数字的个，十，百，千……位数进行的DP。
数位DP的题目有着非常明显的性质：
    询问[l,r]的区间内，有多少的数字满足某个性质
做法根据前缀和的思想，求出[0,l-1]和[0,r]中满足性质的数的个数，然后相减即可。

算法核心

LL dfs(int x,int pre,int bo,int limit);
一般需要以上参数（当然具体情况具体分析）。

    x表示当前的数位（一般都是从高位到低位）
    pre表示前一位的数字
    bo可以表示一些附加条件：是否有前项0，是否当前已经符合条件……
    limit这个很重要！它表示当前数位是否受到上一位的限制，比较抽象，举例说明
    如果上限是135，前两位已经是1和3了，现在到了个位，个位只能是5以下的数字

注：如果当前受限，不能够记忆化，也不能返回记忆化的结果
为了避免多次调用时 每次上限不同 而导致的错
**/
//http://acm.csie.org/ntujudge/view_code.php?id=106844
// Multiples
LL x;
int digit[100];
LL ten_pow[ 15 ];
bool ava[15];
LL dp[15][2][1000000];
LL dfs(int len, LL mod, bool bo, bool limit) {
    if( len < 0 ) return mod == 0;
    if( !limit && dp[len][bo][mod] != -1 ) return dp[len][bo][mod];
    int up = limit? digit[len] : 9;
    LL ret = 0;
    for(int i = 0; i <= up; i++) if( ava[i] || (i==0&&bo)  ) {
        ret += dfs( len-1, (mod+ten_pow[len]*i)%x, bo&&(!i), limit&&(i==up) );
    }
    if( !limit ) dp[len][bo][mod] = ret;
    return ret;
}
LL solve(LL num) {
    int len = 0; digit[0] = 0;
    while( num ) {
        digit[len++] = num%10;
        num /= 10;
    }
    return dfs(len-1, 0,1, 1);
}
bool check(LL num) {
    while( num ) {
        if ( !ava[ num%10 ] ) return false;
        num /= 10;
    }
    return true;
}
int main() {
    LL A, B;
    cin>>x>>A>>B;
    ten_pow[0] = 1;
    mem( dp, -1);
    for(int i = 1; i < 15; i++)
        ten_pow[i] = (ten_pow[i-1]*10)%x;
    string dig; cin>>dig;
    mem(ava, false);
    for(char c : dig) ava[ c-'0' ] = 1;

    if( x <= 1000000 ) {
        cout<< solve(B) - solve(A-1) <<endl;
    }else {
        LL ans = 0;
        LL cur = 0;
        while( cur < A ) cur += x;
        while( cur <= B ) {
            if( check(cur) ) ans++;
            cur += x;
        }
        cout<<ans<<endl;
    }
}
