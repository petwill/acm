#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

int main() {
    char infix[1000];
    stack<char> s;
    scanf("%s", infix);
    int len = strlen(infix);
    for(int i = 0; i < len; i++) {
        if( isalpha(infix[i]) ) putchar(infix[i]);
        else {
            if(infix[i] == '(' ) s.push('(');
            else if(infix[i] == ')') {
                while(!s.empty() && s.top() != '('){
                    putchar(s.top());
                    s.pop();
                }
                assert(s.empty() || s.top() == '(');
                s.pop();
            }
            else if(infix[i] == '+' || infix[i] == '-') {
                if(s.empty() || s.top() == '(') s.push(infix[i]);
                else if(s.top() == '-' || s.top() == '+'){
                    putchar(s.top());
                    s.pop();
                    s.push(infix[i]);
                }
                else {
                    assert(s.top() == '*' || s.top() == '/');
                    s.push(infix[i]);
                }
            }else if(infix[i] == '*' || infix[i] == '/') {
                if(s.empty() || s.top() == '(') s.push(infix[i]);
                else {
                    putchar(s.top());
                    s.pop();
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty()) putchar(s.top()), s.pop();
}
