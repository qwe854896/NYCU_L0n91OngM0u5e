vi g[V]; // 1-index // O(n) build, O(logn) query
int p[V],d[V],sz[V],hs[V];//parent,depth,subtree size,heavy son
int t,tp[V],in[V],rnk[V];//time,top,dfs num(using in DS),rank
struct HeavyLineDCP {
  int n;
  SegmentTree st; // 1-index
  HeavyLineDCP(int n) : n(n) {
    for (int i = 1; i <= n; ++i)
      hs[i] = 0;
      t = 0;
  }
  void DCP(int src=1) {
      d[src] = t = 0;
      d0(src, src);
      d1(src, src, src);
  }
  void d0(int x, int px) {
    p[x] = px;
    sz[x] = 1;

    int h = 0;
    for (int y : g[x])
      if (y != px) {
        d[y] = d[x] + 1;
        d0(y, x);
        sz[x] += sz[y];
        if (sz[y] > h)
          h = sz[y], hs[x] = y;
      }
    }
  void d1(int x, int px, int top) {
    in[x] = ++t;
    rnk[t] = x;
    tp[x] = top;
    if (!hs[x])
      return;
    d1(hs[x], x, top);
    for (int y : g[x])
      if (y != px && y != hs[x])
        d1(y, x, y);
  }
  void build(int w[]) {
    for (int i = 1; i <= n; ++i)
      arr[in[i]] = w[i];
    st = SegmentTree(n);
    st.build(1, 1, n);
  }
  void upd(int s, int x) {
    st.upd(1, 1, n, in[s], x); // upd x on in[s]
  }
  int query(int a, int b) { // max value from a to b
    int ans = 0;
    while (tp[a] != tp[b]) {
      if (d[tp[a]] < d[tp[b]])
        ans=max(ans,st.query(1,1,n,in[tp[b]],in[b])),b=p[tp[b]];
      else
        ans=max(ans,st.query(1,1,n,in[tp[a]],in[a])),a=p[tp[a]];
    }
    if (in[a] > in[b])
      swap(a, b);
    ans = max(ans, st.query(1, 1, n, in[a], in[b]));
    return ans;
  }
};