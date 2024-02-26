struct SCC { // O(V+E)
  int n, m;
  vi g[V], gt[V], gg[V], v;

  vvi c;
  int comp, id[V], in[V];

  void input() {
    cin >> m >> n;
    int i, j; char a, b;
    while (m--) {
      cin >> a >> i >> b >> j; --i, --j;
      i = (i << 1) | (a == '+'), j = (j << 1) | (b == '+');
      g[i ^ 1].pb(j), gt[j].pb(i ^ 1), g[j ^ 1].pb(i), gt[i].pb(j ^ 1);
    }
  }

  SCC() {
    input();
    for (int i = 0; i < n; ++i) v.pb(i);

    for (int i : v) if (!vis[i]) d0(i);
    sort(ALL(v), O);

    CLR(vis, 0);
    for (int i : v) if (!vis[i]) d1(i), ++comp;

    for (int i = 0; i < n; ++i)
      for (int j : g[i])
        if (id[i] != id[j])
          gg[id[i]].pb(id[j]), ++in[id[j]];

    solve();
  }

  bool vis[V];
  int ans[V];
  int solve() {
    for (int i = 0; i < n; ++i)
      if (id[i << 1] == id[(i << 1) | 1])
        return cout << "IMPOSSIBLE\n", 0;
      
    queue <int> q; stack <int> s;
    for (int i = 0; i < comp; ++i) if (!in[i]) q.push(i);
        
    while (!q.empty()) {
      int i = q.front(); q.pop();
      s.push(i);
      for (int j : gg[i]) {
        --in[j]; if (!in[j]) q.push(j);
      }
    }

    CLR(vis, 0);
    while (!s.empty()) {
      int i = s.top(); s.pop();
      bool flag = 0;
      for (int x : c[i])
        if (vis[x >> 1]) { flag = 1; break; }
      
      if (flag) continue;
      
      for (int x : c[i]) {
        vis[x >> 1] = 1;
        ans[x >> 1] = (x & 1);
      }
    }
    for (int i = 0; i < n; ++i) cout << "-+"[ans[i]] << ' ';
    return 1;
  }

  /* old graph */
  int t, out[V];
  void d0(int x) {
    vis[x] = 1;
    for (int y : gt[x]) if (!vis[y]) d0(y);
    out[x] = ++t;
  }

  bool O(int x, int y) {
    return out[x] > out[y];
  }

  /* new graph */
  void d1(int x) {
    vis[x] = 1;
    id[x] = comp;
    c[comp].pb(x);
    for (int y : g[x]) if (!vis[y]) d1(y);
  }
};