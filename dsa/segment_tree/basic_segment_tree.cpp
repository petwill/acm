/******
給你一個序列 AA 包含 NN 個整數，你要對這個序列做以下二種操作：

add l r dadd l r d：將屬於區間 [l,r][l,r] 的元素都加上 dd。
query l rquery l r：詢問區間 [l,r][l,r] 的總和。
********/

#include <bits/stdc++.h>
const int N = 1000500;
using namespace std;
int n, v[N];
typedef long long LL;

struct Node{
    LL val;
    ///lazy tag
    LL tag;
    Node *lc, *rc;
    Node(){val = tag = 0; lc = rc = NULL;}
    void pull(){
        val = lc->val + rc->val;
    }
};
///單點修改
void modify1( Node* node, int L, int R, int i, int d){
    if(L == R){
        assert(L == i);
        node->val += d;
        return;
    }
    int mid = (L + R) >> 1;
    if(mid >= i) modify1(node->lc, L, mid, i, d);
    else modify1(node->rc, mid+1, R, i, d);
    node->pull();
}
void push(Node* node, int L, int R){
    if( !node->tag ) return;
    if (L != R ){
        int mid =(L + R) >> 1;
        node->lc->tag += node->tag;
        node->rc->tag += node->tag;
        node->lc->val += node->tag * (mid-L+1);
        node->rc->val += node->tag * (R-mid);
    }
    node->tag = 0;
}
///區間修改
void modify2( Node *node, int L, int R, int ql, int qr, int d){
    if(ql > R || qr < L) return;
    if(ql <= L && qr >= R){
        node->tag += d;
        node->val += (R-L+1)*d;
        return;
    }
    push( node, L, R );
    int mid = (L + R) >> 1;
    modify2(node->lc, L, mid, ql, qr, d);
    modify2(node->rc, mid+1, R, ql, qr, d);
    node->pull();
}
///ask for sum in range [ql, qr]
LL query(Node *node, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0;
    if(ql <= L && qr >= R) return node->val;
    ///
    push( node, L, R);
    int mid = (L + R) >> 1;
    return query(node->lc, L, mid, ql, qr) + query(node->rc, mid+1, R, ql, qr);
}

Node *build(int L, int R){
    Node *node = new Node();
    if(L == R){
        node->val = v[L];
        return node;
    }
    int mid = (L + R) >> 1;
    node->lc = build(L, mid);
    node->rc = build(mid+1, R);
    node->pull();
    return node;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        Node *root = build(1, n);
        while(m--){
            char tmp[100];scanf("%s", tmp);
            if(tmp[0] == 'q'){
                int a,b;scanf("%d%d", &a, &b);
                printf("ans = %lld\n" ,query(root, 1, n, a, b));
            }
            else {
                int l,r,d;cin>>l>>r>>d;
                modify2(root, 1, n, l, r, d);
            }
        }
    }
    return 0;
}
