struct Disjoint_set {
    #define MAX_N 500005
    // define MAX_N
    int pa[MAX_N], Rank[MAX_N];       
    int sz[MAX_N];
    void init_union_find(int V) {
        for(int i=0; i<V; i++) {
            pa[i] = i;
            Rank[i] = 0;
            sz[i] = 1;
        }
    }
    int find(int x) {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    }
    
    int unite(int x, int y) {
        x = find(x), y = find(y);
        int S = sz[x]+sz[y];
        if(x != y){
            if(Rank[x] < Rank[y]) {
                pa[x] = y; 
                sz[y]=S;
                return y;
            }
            else{
                pa[y] = x;
                sz[x] = S;
                if(Rank[x] == Rank[y]) Rank[x] ++;
                return x;
            }
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
}dsj;
