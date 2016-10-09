#include <bits/stdc++.h>

using namespace std;
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
const int inf = 0x7fffffff; //beware overflow
const LL INF = 0x7fffffffffffffff; //beware overflow
#define mem(x, y) memset(x, (y), sizeof(x) );
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
     return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s << "[ ";
    for (auto it : c) s << it << " ";
    s << "]";
    return s;
}
template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    o << "{";
    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? "" : ", ") << *it;
    return o << "}";
}
template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->fi << ":" << it->se;
    }
    o << "}";
    return o;
}


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

typedef vector<int> VEC;
#define maxn (131075)
int p[maxn];

//fft with modulo, code referenced from the internet
namespace fftMod{
    const int Mod = 1e9 + 7;
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

inline VEC dac( int l, int r ) {
    if( r-l == 1 )  return {1, p[l]};
    int mid = (l+r)>>1;
    VEC le = dac(l, mid), ri= dac(mid, r);
    int mx = max(SZ(le), SZ(ri));
    int len = 1;
    while( len < mx*2 ) len <<= 1;
    le.resize(len, 0);
    ri.resize(len, 0);
    vector<int> res(r-l+1, 0);
    // convolution
    fftMod::fftPrepare(len);
    fftMod::convolution(res, le, ri, len, r-l);
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    vector<int> ans = dac(0, n);
    printf("0");
    for(int p : ans ) printf(" %d", p);
}
