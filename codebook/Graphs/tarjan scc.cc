struct SCC { // 0-based // O(V + E)
	int N, ti = 0;
	vector<vector<int>> adj;
	vector<int> disc, comp, st, comps; // comp[i] : which SCC i is in
	void init(int _N) {
		N = _N;
		adj.resize(N), disc.resize(N), comp = vector<int>(N, -1);
	}
	void ae(int x, int y) { adj[x].push_back(y); } // add edge
	int dfs(int x) {
		int low = disc[x] = ++ti;
		st.push_back(x);  // disc[y] != 0 -> in stack
		for (int y : adj[x])
			if (comp[y] == -1) low = min(low, disc[y] ?: dfs(y));
		if (low == disc[x]) {  // make new SCC, pop off stack until you find x
			comps.push_back(x);
			for (int y = -1; y != x;) comp[y = st.back()] = x, st.pop_back();
		}
		return low;
	}
	void gen() {
		for (int i = 0; i < N; i++)
			if (!disc[i]) dfs(i);
		reverse(begin(comps), end(comps));
	}
};