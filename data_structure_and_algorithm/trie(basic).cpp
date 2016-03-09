#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
char str[1005][25];
int ssize;

struct node {
	node *next[26];
	int cnt[26];
	node() {
		memset(cnt, 0, sizeof(cnt));
		memset(next, 0, sizeof(next));
	}
};
node *root = new node();
void addword(char *w) {
	node *cur = root;
	for(int i = 0; w[i]; i++) {
		int ind = w[i] - 'a';
		if( cur->next[ind] == NULL)
			cur->next[ind] = new node();
		cur->cnt[ ind ]++;
		cur = cur->next[ ind ];
	}
}
int main() {
	ssize = 0;
	while(scanf("%s", str[ssize]) != EOF) {
		ssize++;
		addword( str[ssize-1] );
	}
	for(int i = 0; i < ssize; i++) {
		printf("%s ", str[i]);
		int len = strlen( str[i] );
		node *cur = root;
		for(int j = 0; j < len ;  cur = cur->next[ str[i][j]-'a' ], j++) {
			putchar( str[i][j] );
			if( cur->cnt[ str[i][j] - 'a'] == 1) break;
		}
		putchar('\n');
	}
	return 0;
}
