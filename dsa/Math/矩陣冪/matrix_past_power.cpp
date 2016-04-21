#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define PII pair<long long, long long>
#define fi first
#define se second
const int inf = 0x7fffffff;
const LL  INF = 0x7fffffffffffffff;
const int mod = 10007;
typedef vector<int> vec;
typedef vector<vec> mat;
#define maxn
mat mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < B[0].size(); j++) {
			for(int k = 0; k < A[0].size(); k++)
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
		}
	}
	return C;
}
mat pow(mat A, LL n) {
	mat B(A.size(),vec(A.size()));
	for(int i = 0; i < A.size(); i++)
		B[i][i] = 1;
	while(n > 0) {
		if( n & 1LL)  B = mul(A, B);	
		A = mul(A, A);
		n >>= 1;
	}	
	return B;
}
int main() {
	int T; cin>> T;
	while(T--) {
		LL n; cin >> n;	
		mat A(3, vec(3));
		A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
		A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
		A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
		A = pow(A, n);
		cout << A[0][0] << endl;	
	}
	return 0;
}

