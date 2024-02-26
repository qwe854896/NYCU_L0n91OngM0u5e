/* solve the number of vertex-disjoint routes */
vector <pii> edges; // edge array
vector <int> g[V];  // adjacency list (edge id)
vi ans;
int n;
bool vis[V];
int dep[V];
bool bfs() {
    CLR(vis, 0);
    queue <int> q;
    q.push(0);
    dep[0] = 0;
    vis[0] = 1;
 
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int id : g[i]) {
            int j = edges[id].X;
            if (!vis[j] && edges[id].Y)
                vis[j] = 1, q.push(j), dep[j] = dep[i] + 1;
        }       
    }
 
    return vis[n - 1];
}
 
int cur[V];
int dfs(int i, int a) {
    if (i == n - 1 || !a)
        return a;
    
    int f, flow = 0;
    for (int &id = cur[i]; id < g[i].size(); ++id) {
        int j = edges[g[i][id]].X;
        int &ff = edges[g[i][id]].Y;
        if (dep[i] + 1 == dep[j] && (f = dfs(j, min(a, ff)))) {
            ff -= f;
            edges[g[i][id] ^ 1].Y += f;
            a -= f;
            flow += f;
            if (!a)
                break;
        }
    }
    return flow;
}
 
int dinic() { // O(V^2 * E) // O(E * sqrt(V)) if all edge has same weight
    int cnt = 0;
    while ( bfs() ) {
        CLR(cur, 0);
        cnt += dfs(0, INF);
    }
    return cnt;
}
 
bool dfs1(int i) {
    ans.pb(i);
    if (i == n - 1)
        return true;
    for (int id : g[i]) {
        if (!(id & 1) && !edges[id].Y) {
            edges[id].Y = 1; // make this edge unusable
            if (dfs1(edges[id].X))
                return true;
        }
    }
    return false;
}
 
signed main () {
    // input n, m
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; 
        g[a].pb(edges.size());
        edges.pb(pii(b, 1));
        g[b].pb(edges.size());
        edges.pb(pii(a, 0));
    }
    
    int cnt = dinic();
    while (cnt--) {
        ans.clear();
        dfs1(0);
        // print ans
    }
    return 0;
}