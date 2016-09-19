typedef long double ld;
/* N must be 2^k and greater than array.size()
 * FFT( a );
 * FFT( b );
 * for(int i = 0; i<N; ++i) c[i] = conj(a[i] * b[i]);
 * FFT( c );
 * for(int i = 0; i<N; ++i) c[i] = conj(c[i]);
 * for(int i = 0; i<N; ++i) c[i] /= N;
 */
void FFT(vector< complex<ld> >& v) {
    int N = v.size();
    for(int i = 1, j = 0; i<N; ++i) {
        for(int k = N>>1; !((j^=k)&k); k>>=1);
        if(i>j) swap(v[i],v[j]);
    }
    for(int k = 2; k<=N; k<<=1) {
        ld w = -2.0*pi/k;
        complex<ld> deg(cos(w),sin(w));
        for(int j = 0; j<N; j+=k) {
            complex<ld> theta(1,0);
            for(int i = j; i<j+k/2; ++i) {
                complex<ld> a = v[i];
                complex<ld> b = v[i+k/2]*theta;
                v[i] = a+b;
                v[i+k/2] = (a-b);
                theta *= deg;
            }
        }
    }
}
