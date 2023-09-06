void findConvexHull(int n) {
 sort(v, v + n);
 int u = 0, d = 0;
 for (int i = 0; i < n; ++i) {
  while (d >= 2 && dc[d - 2].cross(dc[d - 1], v[i]) < 0)
   --d, dc.pop_back();
  while (u >= 2 && uc[u - 2].cross(uc[u - 1], v[i]) > 0)
   --u, uc.pop_back();
  dc.pb(v[i]);
  ++d;
  uc.pb(v[i]);
  ++u;
 }
}