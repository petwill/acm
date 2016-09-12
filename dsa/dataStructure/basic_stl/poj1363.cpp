// poj 1363 Rails
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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
int main() {
    stack<int> left, down;
    int n, tmp;
    while(scanf("%d", &n)==1 && n) {
        while(scanf("%d", &tmp) ==1 && tmp ) {
             while( !left.empty() ) left.pop();
             while( !down.empty() ) down.pop();
             for(int i = n; i >= 1; i--) left.push(i);
             int i;
             vector<int> arr(n);
             assert( arr.size() == n);
             arr[0] = tmp; for(int i=1;i<n;i++) scanf("%d", &arr[i]);
             for(i = 0; i < n; i++) {
                 int now = arr[i];
                 if( left.empty() || now < left.top() ) {
                     if( now != down.top() ) {printf("No");break;}
                     else down.pop();
                 }
                 else if( now == left.top() ) left.pop();
                 else {
                     // now > left.top()
                     while(left.top() < now) down.push(left.top()), left.pop();
                     assert( left.top() == now );
                     left.pop();
                 }
            }
            if( i == n ) printf("Yes");
            puts("");
        }
        puts("");
    }
	return 0;
}
