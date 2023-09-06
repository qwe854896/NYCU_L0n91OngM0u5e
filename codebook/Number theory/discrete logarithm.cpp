// Computes x which a ^ x = b mod n.
ll d_log(ll a, ll b, ll n) {
  ll m = ceil(sqrt(n));
  ll aj = 1;
  map<ll, ll> M;
  for (int i = 0; i < m; ++i) {
    if (!M.count(aj))
      M[aj] = i;
    aj = (aj * a) % n;
  }

  ll coef = qp(a, n - 2, n);
  coef = qp(coef, m, n);
  // coef =  a ^ (-m)
  ll gamma = b;
  for (int i = 0; i < m; ++i) {
    if (M.count(gamma)) {
      return i * m + M[gamma];
    } else {
      gamma = (gamma * coef) % n;
    }
  }
  return -1;
}
