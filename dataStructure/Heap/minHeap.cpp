#define maxn 20005
class min_heap{
public:
    min_heap() {sz=0;memset(data, 0, sizeof(data));}
    int data[maxn];
    int sz;
    int top() {
        return data[1];
    }
    void push(int a) {
        data[++sz] = a;
        int now = sz;
        while(data[now] < data[now>>1] && now > 1) {
            swap( data[now>>1], data[now]);
            now >>= 1;
        }
    }
    void pop() {
        data[1] = data[sz--];
        int now = 1;
        while(now*2 <= sz) {
            int ind = (now*2+1 <= sz && data[now*2] > data[now*2+1])?now*2+1:now*2;
            if( data[now] <= data[ind] ) break;
            swap(data[now], data[ind]), now = ind;
        }
    }
    int size() {
        return sz;
    }
};
