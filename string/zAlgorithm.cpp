//z algorithm
/**
    定義一個函數 z() ， 
    z(i) 是指由 s[i] 開始的字串，與 s[0] 開始的字串可以匹配到多長。
    也就是說 s[0 ... z(i)-1] = s[i ... i+z(i)-1] 
**/
// get a practice here http://codeforces.com/blog/entry/3107

#include <bits/stdc++.h>

using namespace std;
string str;
int z[100000];

void build_z(){
    int L, R;
    L = R = 0, z[0] = 0;
    for(int i = 1; i < len; i++){
        if(i > R) z[i] = 0;
        else{
            int ip = i - L;
            if(ip + z[ip] < z[L] ) z[i] = z[ip];
            else z[i] = R - i + 1;
        }
        while( i + z[i] < len && str[ i+z[i] ] == str[ z[i] ] )
            z[i]++;
        if( i + z[i] - 1 > R ) L = i, R = i + z[i] - 1;   
    }
}

int main(){
    int T;cin>>T;
    while(T--){
        cin >> str ;
        build_z();
    }
    return 0;
}
