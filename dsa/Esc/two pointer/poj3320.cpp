#include <set>
#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

set<int> st;
map<int,int> mp;
int P, a[1000005];

int main(){
    cin>>P;
    for(int i = 0; i < P; i++){
        scanf("%d" ,&a[i]);
        st.insert(a[i]);
    }
    int num = st.size();
    int s = 0, t = 0, ans = P, now = 0;
    while(t < P){
        while(t<P && now < num){
            if(mp[a[t]]++ == 0) now++;
            t++;
        }
        if(now < num) break;
        ans = min(ans, t - s);
        mp[a[s]]--;
        if(mp[a[s]] == 0) now--;
        s++;
    }
    cout << ans << endl;
}
