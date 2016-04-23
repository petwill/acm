#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("out", "w", stdout);
    int T;cin>>T;
    for(int qq = 1; qq <= T; qq++) {
        printf("Case #%d: ", qq);
        char n[10000];scanf("%s", n);
        int len = strlen(n);
        deque<char> deq;
        deq.push_back(n[0]);
        for(int i = 1; i < len; i++) {
            if(n[i] >= deq.front()) deq.push_front(n[i]);
            else deq.push_back(n[i]);
        }
        while( !deq.empty() ) {
            char c=deq.front();deq.pop_front();
            printf("%c", c);
        }
        putchar('\n');
    }
	return 0;
}

