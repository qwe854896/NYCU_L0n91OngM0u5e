const int MN = 20002;
struct tarjan_scc {
 /* scc for each vertex; low; dep; is stk; */
 int scc[MN], low[MN], d[MN], stacked[MN];
 int ticks, current_scc;  // some id
 deque<int> s;            // used as stack.

 tarjan_scc() {}

 void init() {
  memset(scc, -1, sizeof scc);
  memset(d, -1, sizeof d);
  memset(stacked, 0, sizeof stacked);
  s.clear();
  ticks = current_scc = 0;
 }

 void compute(vector<vector<int> > &g, int u) {
  d[u] = low[u] = ticks++;
  s.push_back(u);
  stacked[u] = true;
  for (int v : g[i]) {
   int v = g[u][i];
   if (d[v] == -1) compute(g, v);
   if (stacked[v]) {
    low[u] = min(low[u], low[v]);
   }
  }

  if (d[u] == low[u]) {  // root
   int v;
   do {
    v = s.back();
    s.pop_back();
    stacked[v] = false;
    scc[v] = current_scc;
   } while (u != v);
   current_scc++;
  }
 }
};
