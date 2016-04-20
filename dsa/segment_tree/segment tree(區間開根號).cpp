#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll value[100005];
int n;

struct Node {
    Node *l,*r;
    int lc,rc;
    ll val;
    Node(int a,int b){val = 0; l = NULL; r = NULL; lc = a; rc = b;}
    Node(){};
    void pull(){
        if(rc - lc == 1) return;
        val = 0;
        if(l!=NULL) val += l->val;
        if(r!=NULL) val += r->val;
    }
};

struct Tree {

    Node *root;

    Node* build(int l,int r){
        Node* now = new Node(l,r);
        if(r-l==1){
            if(l<n) now->val = value[l];
            return now;
        }
        int mid = (l+r) >> 1;
        now->l = build(l,mid);
        now->r = build(mid,r);
        now->pull();
        return now;
    }

    void modify(Node* node,ll n,int l,int r){
        if(node->lc >= r || node->rc <= l ) return;

        if(node->rc - node->lc == 1){
            node->val = n;
            return;
        }
        int mid = (node->rc+node->lc) /2;
        modify(node->r,n,l,r);
        modify(node->l,n,l,r);
        node->pull();
        return;
    }

    ll query(Node* node,int l,int r){
        if(node->lc >=l && node->rc <=r)
            return node->val;
        if(node->lc >= r || node->rc <= l ) return 0;
        return query(node->l,l,r)+query(node->r,l,r);

    }

}tree;

Node* build(int l,int r){
    Node* now = new Node(l,r);
    if(r-l==1){
        if(l<n) now->val = value[l];
        return now;
    }
    int mid = (l+r) >> 1;
    now->l = build(l,mid);
    now->r = build(mid,r);
    now->pull();
    return now;
}

void sqrtt(Node *node, int l,int r){
    if(node->lc >= r || node->rc <= l || node->val <= node->rc - node->lc) return;
    if(node->rc - node->lc == 1){
        node->val = (int)sqrt(node->val);
        return;
    }
    sqrtt(node->l,l,r);
    sqrtt(node->r,l,r);
    node->pull();
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d %d",&n,&q);
        for(int h=0;h<n;h++) scanf("%lld",&value[h]);
        tree.root = tree.build(0, n);
        int type;
        while(q--){
            scanf("%d",&type);
            if(type==0){
                int l,r;
                ll val;
                scanf("%d %d",&l,&r);
                sqrtt(tree.root,l-1,r);
            }
            if(type==1){
                int l,r;
                ll val;
                scanf("%d %lld",&l,&val);
                tree.modify(tree.root,val,l-1,l);
            }
            if(type==2){
                int l,r;
                scanf("%d %d",&l,&r);
                printf("%lld\n",tree.query(tree.root,l-1,r));
            }
        }
    }
    return 0;
}
