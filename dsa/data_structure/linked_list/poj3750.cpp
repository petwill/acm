#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

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
struct node{
    string name;
    node *next, *prev;
    node() {next = prev = NULL;}
};
int main() {
#ifdef DEBUG
	freopen("out", "w", stdout);
#endif
    int n;cin>>n;
    node *ptr = new node();
    node *head = ptr;
    if( n ) cin >> ptr->name;
    for(int i = 1; i < n; i++) {
        ptr->next = new node();
        ptr->next->prev = ptr;
        ptr = ptr->next;
        cin >> ptr->name;
    }
    ptr->next = head;
    head->prev = ptr;
    int w, s;
    scanf("%d,%d", &w, &s);w--;
    while(w--) head = head->next;
    while(1) {
        for(int i = 0; i < s-1; i++) head = head->next;
        cout << head->name << endl;
        if( head->next == head) return 0;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
	return 0;
}
