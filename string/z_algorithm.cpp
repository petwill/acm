#include <bits/stdc++.h>

using namespace std;
string str;
int fail[100000], z[100000];
int len;
char tmp[1000000];
int ans;

void build_z(){
    int L, R;
    L = R = 0, z[0] = 0;
    for(int i = 1; i < len; i++){
        if(i > R) z[i] = 0;
        else{
            int ip = i - L;
            if(ip + z[ip] < z[L]) z[i] = z[ip];
            else z[i] = R - i + 1;
        }
        while(i + z[i] < len && str[i+z[i]] == str[0+z[i]])
            z[i]++;

        if(i+z[i]-1>R) L = i, R = i+z[i]-1;

        if(len%i == 0 && z[i]+i == len) {ans = i;break;}
    }
}

int main(){
    int T;cin>>T;
    while(T--){
        scanf("%s" ,tmp);
        len = strlen(tmp);
        str = string(tmp);
        //z algorithm
        ans = len;
        build_z();
        printf("%d\n", ans);
    }
    return 0;
}
