#include <iostream>
#include<stdio.h>

using namespace std;

int main() {
	const int len = 7;
	int num[len + 1] = { 1 };

	for (int i = 1; i <= len; ++i)
		for (int j = i; j <= len; ++j){
		    num[j] += num[j - i];
			//printf("num[%d]+=num[%d]\n",j,j-i);
        }

	for (int i = 0; i <= len; i++)
		cout << "p(" <<i << ") = " << num[i] << endl;
	return 0;
}
