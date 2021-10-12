struct query {
    int l, r, i;
    void input(int id) {
        i = id;
        cin >> l >> r;
    }
    bool operator<(const query& b) {
        return r < b.r;
    }
} Q[V];
 
int n, qc, ans[V], lst_vis[V], x[V];
vi xc;
 
signed main () {
    // input
    for (int i = 0; i < n; ++i)
        cin >> x[i], xc.pb(x[i]);
    
    for (int i = 0; i < q; ++i)
        Q[i].input(i);
 
    sort(Q, Q + q); // sort all queries
    sort(ALL(xc)); // discrete all color
 
    for (int i = 0; i < n; ++i) {
        int j = LB(xc, x[i]);
        if (lst_vis[j])     add(lst_vis[j], -1);
        lst_vis[j] = i + 1; add(lst_vis[j], 1);
        while (qc < q && Q[qc].r == i)
            ans[Q[qc].i] = sum(i + 1) - sum(Q[qc].l), ++qc;
    }
    // output answer
}