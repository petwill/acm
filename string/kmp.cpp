#include <bits/stdc++.h>

using namespace std;
string str;
int fail[100000];
int len;
char tmp[1000000];


void build_fail(){
    int current_pos = fail[0] = -1;
    for(int i = 1; i < len; i++){
        while(current_pos != -1 && str[current_pos+1] != str[i]){
            current_pos = fail[current_pos];
        }
        if(str[current_pos+1] == str[i]) current_pos++;
        fail[i] = current_pos;
    }
}
int main(){
    int T;cin>>T;
    while(T--){
        scanf("%s" ,tmp);
        len = strlen(tmp);
        str = string(tmp);
        build_fail();
        int ans = len-1-fail[len-1];
        if(len%ans == 0) {
            printf("%d\n", ans);
        }else
            printf("%d\n", len);
    }
    return 0;
}
