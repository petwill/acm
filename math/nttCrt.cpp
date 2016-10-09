constexpr int mod = 1e9+7;
typedef vector<int> VEC;
// ntt + Crt, code referenced from the internet
namespace nttCrt {
    constexpr int magic[3] = {1004535809, 998244353, 104857601};
    constexpr int MOD = 1000000007;
    constexpr int G = 3;
    int P;
    inline int quick_mod(int x, int k, int MOD) {
        int ans = 1;
        while (k) {
            if (k&1) ans = 1LL * ans * x % MOD;
            x = 1LL * x * x % MOD;
            k >>= 1;
        }
        return ans;
    }
    inline void change(int *y, int len) {
        for(int i = 1, j = len / 2; i < len - 1; i++) {
            if(i < j) swap(y[i], y[j]);
            //交换互为小标反转的元素，i<j保证交换一次
            //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
            int k = len / 2;
            while(j >= k) {
                j -= k;
                k /= 2;
            }
            if(j < k) j += k;
        }
    }
    inline void ntt(int *y, int len, int on) {
        change(y, len);
        for(int h = 2; h <= len; h <<= 1) {
            int wn = quick_mod(G, (P - 1) / h, P);
            for(int j = 0; j < len; j += h) {
                int w = 1;
                for(int k = j; k < j + h / 2; k++) {
                    int u = y[k] % P;
                    int t = 1LL * w * y[k + h / 2] % P;
                    y[k] = (u + t) % P;
                    y[k + h / 2] = ((u - t) % P + P) % P;
                    w = 1LL * w * wn % P;
                }
            }
        }
        if(on == -1) {
            for (int i = 1; i < len / 2; i++)
                swap(y[i], y[len - i]);
            int inv = quick_mod(len, P - 2, P);
            for(int i = 0; i < len; i++)
                y[i] = 1LL * y[i] * inv % P;
        }
    }

    int n;
    int r[3][3];

    inline int CRT(int *a) {
        int sb[3] = {a[0], a[1], a[2]};
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < i; ++j) {
                int t = (sb[i] - sb[j]) % magic[i];
                if(t < 0) t += magic[i];
                sb[i] = 1LL * t * r[j][i] % magic[i];
            }
        }
        int mul = 1, ans = sb[0] % MOD;
        for(int i = 1; i < 3; ++i) {
            mul = 1LL * mul * magic[i - 1] % MOD;
            ans = (ans + 1LL * sb[i] * mul) % MOD;
        }
        return ans;
    }
    int tmp[maxn][3];
    int x1[maxn*2], x2[maxn*2];

    inline void gao(vector<int>& res, vector<int> &a, vector<int> &b ,int len, int kk) {

        for (int ti = 0; ti < 3; ti++) {
            P = magic[ti];
            int k;
            for ( k = 0; k < SZ(a) && k < len; k++) x1[k] = a[k];
            for ( ;k < len; k++) x1[k] = 0;
            for ( k = 0; k < SZ(b) && k < len; k++) x2[k] = b[k];
            for ( ;k < len; k++) x2[k] = 0;

            ntt(x1, len, 1); ntt(x2, len, 1);
            for (int i = 0; i < len; i++) x1[i] = 1LL * x1[i] * x2[i] % P;
            ntt(x1, len, -1);

            for (int i = 0; i <= kk; i++) tmp[i][ti] = x1[i];
        }
        for (int i = 0; i <= kk; i++) res[i] =  CRT(tmp[i])  ;
    }
    inline void init() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                r[i][j] = quick_mod(magic[i], magic[j] - 2, magic[j]);
            }
        }
    }
};
