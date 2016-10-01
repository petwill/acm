//integer partition
/**
    For example, 4 can be partitioned in five distinct ways:
    4
    3 + 1
    2 + 2
    2 + 1 + 1
    1 + 1 + 1 + 1
**/
#include <iostream>
using namespace std;

int main() {
	const int len = 121;
	int num[len + 1] = { 1 };

	for (int i = 1; i <= len; ++i)
		for (int j = i; j <= len; ++j)
			num[j] += num[j - i];

	for (int i = 0; i <= len; i++)
		cout << i << ' ' << num[i] << endl;
	return 0;
}
