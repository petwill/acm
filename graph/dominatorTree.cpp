//http://acm.csie.org/ntujudge/contest_view.php?contest_id=465&id=2658
// template referenced from the internet
/**
    A dominator tree is a tree where each node's children are those nodes it immediately dominates.
    Because the immediate dominator is unique, it is a tree.
    The start node is the root of the tree.
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAXN = 200000 + 10;
namespace DominatorTree {
  int dfn[MAXN], pre[MAXN], pt[MAXN], sz;
  int semi[MAXN], dsu[MAXN], idom[MAXN], best[MAXN];
  int get(int x) {
    if (x == dsu[x]) return x;
    int y = get(dsu[x]);
    if (semi[best[x]] > semi[best[dsu[x]]]) best[x] = best[dsu[x]];
    return dsu[x] = y;
  }
  void dfs(int u, const VI succ[]) {
    dfn[u] = sz; pt[sz ++] = u;
    for (auto &v: succ[u]) if ( dfn[v] == -1 ) {
      dfs(v, succ); pre[dfn[v]] = dfn[u];
    }
  }
  void tarjan(const VI pred[], VI dom[]) {
    for (int j = sz - 1, u; u = pt[j], j > 0; -- j) {
      for (auto &tv: pred[u]) if ( dfn[tv] != -1) {
        int v = dfn[tv]; get(v);
        if (semi[best[v]] < semi[j]) semi[j] = semi[best[v]];
      }
      dom[semi[j]].push_back(j);
      int x = dsu[j] = pre[j];
      for (auto &z: dom[x]) {
        get(z);
        if (semi[best[z]] < x) idom[z] = best[z];
        else idom[z] = x;
      }
      dom[x].clear();
    }
    for (int i = 1; i < sz; ++ i) {
      if (semi[i] != idom[i]) idom[i] = idom[idom[i]];
      dom[idom[i]].push_back(i);
    }
  }
  void build(int n, int s, const VI succ[], const VI pred[], VI dom[]) {
    //init
    for (int i = 0; i < n; ++ i) {
      dfn[i] = -1; dom[i].clear();
      dsu[i] = best[i] = semi[i] = i;
    }
    sz = 0; dfs(s, succ); tarjan(pred, dom);
  }
}
using DominatorTree::dfn;

VI pred[MAXN], succ[MAXN], dom[MAXN];
int a[MAXN], b[MAXN], st[MAXN], ed[MAXN];
int n, m, sz;

void dfs(int u) {
  st[u] = sz ++;
  for (auto &v: dom[u]) dfs(v);
  ed[u] = sz ++;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n + m; ++ i) {
      pred[i].clear(); succ[i].clear();
    }
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      a[i] = -- u; b[i] = -- v;
      succ[u].push_back(v);
      pred[v].push_back(u);
    }
    // 0 as the starting point
    DominatorTree::build(n, 0, succ, pred, dom);
    // result returns as a tree, stored in dom
    // zero-based
    sz = 0; dfs(0);
    VI ret;
    for (int i = 0; i < m; ++ i) {
      int u = dfn[a[i]], v = dfn[b[i]];
      if (u == -1 || v == -1) continue;
      //if v dominates u ==> not a useful road
      if (st[v] <= st[u] && ed[v] >= ed[u]) continue;
      ret.push_back(i + 1);
    }

    printf("%d\n", (int)ret.size());
    for (auto &x: ret) printf("%d ", x);
    puts("");
  }
  return 0;
}

