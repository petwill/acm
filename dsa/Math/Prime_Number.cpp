#include <cstdio>
#include <map>
#include <iostream>

using namespace std;


bool is_prime(int n){
    for(int i=2; i*i <= n; i++)
        if(n%i == 0)
            return false;
    return n != 1; //1 is an exception
}

map<int,int> prime_factor(int n){
    map<int,int> res;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            res[i]++;
            n/=i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
int main(){
    map<int,int> mp;
    int n;cin>>n;
    mp = prime_factor(n);
    for(std::map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
        printf("mp[%d] = %d\n", it->first, it->second);
    return 0;
}
