#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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
#define maxn 100005
#define maxm 5005

int n, m, arr[maxn], sorted[maxn];
const int bucket_size = (int)sqrt(maxn);
const int max_num_of_bucket = (int)ceil(maxn/bucket_size);
//vector<int> bucket[max_num_of_bucket];
vector<int> bucket[1000];

int main() {
    cin >> n >> m;
    int num_of_bucket = n/bucket_size;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]), sorted[i] = arr[i];
        bucket[i/bucket_size].pb( arr[i] );
    }
    sort( sorted, sorted+n);
    /*
    for(int i = 0; i < num_of_bucket; i++) {
        for(int j = 0; j < bucket_size; j++) {
             bucket[i].pb( arr[i*bucket_size+j] );
        }
    }
    */
    for(int i = 0; i < num_of_bucket; i++) sort( all(bucket[i]) );
    while( m-- ) {
        int L, R, k; scanf("%d%d%d", &L, &R, &k);
        int lb = -1, ub = n-1;
        L--;//R--;
        // [left, right] is completely in bucket
        while( ub - lb > 1 ) {
            int mid = (lb+ub)>>1;
            int x = sorted[mid];
            int cnt = 0;
            // there is cnt number of numbers smaller or equal to x
            int tl = L, tr = R;
            while(tl < tr && tl%bucket_size != 0) if(arr[tl++] <= x) cnt++;
            while(tr > tl && tr%bucket_size != 0) if(arr[--tr] <= x) cnt++;
            //cnt += (arr[tr] <= x);
            for(int qq = tl/bucket_size; qq < tr/bucket_size; qq++) {
                cnt += (upper_bound(all(bucket[qq]), x) - bucket[qq].begin() );
            }
            if( cnt >= k ) ub = mid;
            else lb = mid;
        }
        printf("%d\n", sorted[lb]);
    }
	return 0;
}

