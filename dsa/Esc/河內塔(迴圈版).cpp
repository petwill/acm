#include<iostream>

using namespace std;
main(){
    int n ;
    cin>>n;

    for (int i = 1; i < (1 << n); i++) {
        int from, to;
        from = (i&i-1)%3 ;
        to = ((i|i-1)+1)%3 ;
        cout << from+1 << " --> " << to+1 << endl;
    }
}
