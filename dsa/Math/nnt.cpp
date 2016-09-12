/*
NTT( a );
NTT( b );
for(int i = 0; i<N: ++i)
    c[i] = (long long) a[i] * b[i] % mod;
NTT( c, true );
for(int i = 0; i<N; ++i)
    c[i] = (786433LL-12) * c[i] % mod;
*/

constexpr int mod = 786433;
constexpr int N = 65536;

void NTT(vector< int >& v, bool flag = false)
{
    for(int i = 1, j = 0; i<N; ++i)
    {
        for(int k = N>>1; !((j^=k)&k); k>>=1);
        if(i>j) swap(v[i],v[j]);
    }
    for(int k = 2; k<=N; k<<=1)
    {
        int deg = mypow(flag ? 524289 : 3, N / k);
        for(int j = 0; j<N; j+=k)
        {
            int theta = 1;
            for(int i = j; i<j+k/2; ++i)
            {
                int a = v[i];
                int b = (long long) v[i+k/2]*theta%mod;
                v[i] = (a+b) % mod;
                v[i+k/2] = (a-b+mod)%mod;
                theta = (long long) theta * deg % mod;
            }
        }
    }
}
