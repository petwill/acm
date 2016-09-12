
    template for 樹鍊剖分
    careful => node index [1..n]
    siz[v]表示以v为根的子树的节点总数。
    dep[v]表示v的深度。
    max-son[v]表示与v在同一重链上的v的儿子节点。
    pa[v]表示v的父亲节点。
    top[v]表示v所在链的顶端节点。
    link[v]表示节点v在线段树中的位置。
    siz[],son[],fa[],dep[]可以在第一遍dfs中求出来，
    link-top[]，link[]可在第二遍dfs中求出来。具体过程看代码吧。

    link[root] = 1,  link[ 1..n ] = permutation of [1..n]

    HLD for operation on edges =>
        seg_arr[0] won't be queried cause this edge actually doesn't exist
        seg_arr[ 1..n ) is actually used
        every edge in segment tree's index == w[ the deeper node index ]
