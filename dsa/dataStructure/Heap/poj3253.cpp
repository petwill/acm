#include <cstdio>
#include <iostream>
#include <cstring>
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
#define maxn 20005
class min_heap{
public:
    min_heap() {sz=0;memset(data, 0, sizeof(data));}
    int data[maxn];
    int sz;
    int top() {
        return data[1];
    }
    void push(int a) {
        data[++sz] = a;
        int now = sz;
        while(data[now] < data[now>>1] && now > 1) {
            swap( data[now>>1], data[now]);
            now >>= 1;
        }
    }
    void pop() {
        data[1] = data[sz--];
        int now = 1;
        while(now*2 <= sz) {
            int ind = (now*2+1 <= sz && data[now*2] > data[now*2+1])?now*2+1:now*2;
            if( data[now] <= data[ind] ) break;
            swap(data[now], data[ind]), now = ind;
        }
    }
    int size() {
        return sz;
    }
};
int main() {
#ifdef DEBUG
	freopen("out", "w", stdout);
#endif
    //priority_queue<int, vector<int>, greater<int> > que;
    // try with a min_heap
    min_heap que;
    int n;cin >> n;
    while(n--) {int a;cin>>a;que.push(a);}
    LL ans = 0;
    while( que.size() > 1) {
        int a =  que.top(); que.pop();
        int b =  que.top(); que.pop();
        ans += (a+b);
        que.push(a+b);
    }
    cout << ans << endl;
	return 0;
}
