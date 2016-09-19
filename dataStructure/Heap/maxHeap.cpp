#define maxn 10005
class max_heap{
public:
    int sz, data[maxn];
    max_heap() {sz = 0;}
    void push(int a) {
        data[++sz] = a;
        int now = sz;
        while( now > 1 ) {
            if( data[now] > data[now>>1] ) {
                swap(data[now], data[now>>1]);
                now >>= 1;
            }else break;
        }
    }
    int top() {
        return data[1];
    }
    void pop() {
        data[1] = data[sz--];
        int now = 1;
        while( now*2 <= sz ) {
            int ind = (now*2+1 <= sz && data[(now<<1)+1] > data[now<<1])?now*2+1:now<<1;
            if( data[now] < data[ind] ) swap( data[now], data[ind]), now = ind;
            else break;
        }
    }
    bool empty() {
        return sz==0;
    }
};
