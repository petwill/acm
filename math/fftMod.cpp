struct Complex {
    double x , y;
    Complex (double _x = 0 , double _y = 0) {
        x = _x , y = _y;
    }
    Complex operator + (const Complex &r) const {
        return Complex(x + r.x , y + r.y);
    }
    Complex operator - (const Complex &r) const {
        return Complex(x - r.x , y - r.y);
    }
    Complex operator * (const Complex &r) const {
        return Complex(x * r.x - y * r.y , x * r.y + y * r.x);
    }
    Complex conj () const {
        return Complex(x , -y);
    }
    double operator = (const double a) {
        *this = Complex(a , 0);
        return a;
    }
};
const double pi = acos(-1.0);
//fft with modulo, code referenced from the internet
/*
    fftMod::fftPrepare(len);
    fftMod::convolution(res, le, ri, len, r-l);
*/
namespace fftMod{
    const int Mod = 1e9 + 7;
    // to do
    const int N = 1 << 18;
    const int M = 32768;
    int p[N] , I[N] ;
    int t1[N] , t2[N] , t3[N];

    Complex w[N];
    int rev[N];

    void fftPrepare(int n) {
        int LN = __builtin_ctz(n);
        for (int i = 0 ; i < n ; ++ i) {
            double ang = 2 * pi * i / n;
            w[i] = Complex(cos(ang) , sin(ang));
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LN - 1));
        }
    }
    void FFT(Complex P[], int n, int oper) {
        for (int i = 0 ; i < n ; i ++) {
            if (i < rev[i]) {
                swap(P[i], P[rev[i]]);
            }
        }
        for (int d = 0; (1 << d) < n; d++) {
            int m = 1 << d, m2 = m * 2 , rm = n / m2;
            for (int i = 0; i < n; i += m2) {
                for (int j = 0; j < m; j++) {
                    Complex &P1 = P[i + j + m], &P2 = P[i + j];
                    Complex t = w[rm * j] * P1;
                    P1 = P2 - t;
                    P2 = P2 + t;
                }
            }
        }
    }

    Complex A[N] , B[N] , C1[N] , C2[N];
    void convolution(vector<int> &res, vector<int> &a, vector<int> &b, int len, int K) {
        // a[ 0 .. len ) and b[ 0 .. len )'s convolution % Mod
        // stored in res[ 0 .. K+1 )
        for (int i = 0 ; i < len ; ++ i) {
            A[i] = Complex(a[i] / M , a[i] % M);
            B[i] = Complex(b[i] / M , b[i] % M);
        }
        FFT(A , len , 1); FFT(B , len , 1);

        for (int i = 0 ; i < len ; ++ i) {
            int j = i ? len - i : i;
            Complex a1 = (A[i] + A[j].conj()) * Complex(0.5 , 0);
            Complex a2 = (A[i] - A[j].conj()) * Complex(0 , -0.5);
            Complex b1 = (B[i] + B[j].conj()) * Complex(0.5 , 0);
            Complex b2 = (B[i] - B[j].conj()) * Complex(0 , -0.5);
            Complex c11 = a1 * b1 , c12 = a1 * b2;
            Complex c21 = a2 * b1 , c22 = a2 * b2;
            C1[j] = c11 + c12 * Complex(0 , 1);
            C2[j] = c21 + c22 * Complex(0 , 1);
        }
        FFT(C1 , len , -1); FFT(C2 , len , -1);

        for (int i = 0 ; i <= K ; ++ i) {
            int x = (LL)(C1[i].x / len + 0.5) % Mod;
            int y1 = (LL)(C1[i].y / len + 0.5) % Mod;
            int y2 = (LL)(C2[i].x / len + 0.5) % Mod;
            int z = (LL)(C2[i].y / len + 0.5) % Mod;
            res[i] = ((LL)x * M * M + (LL)(y1 + y2) * M + z) % Mod;
        }
    }
};

