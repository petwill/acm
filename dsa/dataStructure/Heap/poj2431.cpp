#include <cstdio>
#include <utility>
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
const int inf = 0x7fffffff;
const LL  INF = 0x7fffffffffffffff;
const int mod = 1e9+7;
typedef vector<int> vec;
typedef vector<vec> mat;
#define maxn 10005
class max_heap{
public:
    int sz, data[maxn];
    max_heap() {sz = 0;}
    void push(int a) {
        data[++sz] = a;
        int now = sz;
        while( now > 1 ) {
            if( data[now] > data[now>>1] ) {
                swap(data[now], data[now>>1]);
                now >>= 1;
            }else break;
        }
    }
    int top() {
        return data[1];
    }
    void pop() {
        data[1] = data[sz--];
        int now = 1;
        while( now*2 <= sz ) {
            int ind = (now*2+1 <= sz && data[(now<<1)+1] > data[now<<1])?now*2+1:now<<1;
            if( data[now] < data[ind] ) swap( data[now], data[ind]), now = ind;
            else break;
        }
    }
    bool empty() {
        return sz==0;
    }
};
pii p[maxn];
int A[maxn], B[maxn];
int main() {
    //priority_queue<int> que;
    max_heap que;
    int n;cin>> n;
    for(int i=n-1;i>=0;i--)
        scanf("%d%d", &p[i].fi, &p[i].se);
    int L, left;
    cin >> L >> left;
    for(int i = 0; i < n; i++) p[i].fi = L - p[i].fi;
    sort(p, p+n);
    for(int i=0;i<n;i++) A[i] = p[i].fi, B[i] = p[i].se;
    A[n] = L ;B[n] = 0;
    n++;
    int ans = 0,pos = 0; ;
    for(int i = 0; i < n; i++) {
        // trying to reach A[i]
        int d = A[i] - pos;
        while( left < d ) {
            if( que.empty() ) return puts("-1"), 0;
            left += que.top();
            que.pop();
            ans++;
        }
        que.push( B[i] );
        left -= d;
        pos = A[i];
    }
    cout << ans << endl;
    return 0;
}
