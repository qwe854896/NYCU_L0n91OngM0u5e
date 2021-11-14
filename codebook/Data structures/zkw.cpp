int n, zkw[V]; // 0-index
void build() {
  for (int i = n - 1; i > 0; --i)
    zkw[i]=max(zkw[i<<1],zkw[i<<1|1]);
}
void modify(int p, int v) {
  for(zkw[p +=n]=v; p > 1; p >>= 1)
    zkw[p>>1]=max(zkw[p],zkw[p^1]);
}
int query(int l, int r) {
  int ret = -0x3f3f3f3f;
  for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if (l&1) ret=max(ret, zkw[l++]);
    if (r&1) ret=max(ret, zkw[--r]);
  }
  return ret;
}