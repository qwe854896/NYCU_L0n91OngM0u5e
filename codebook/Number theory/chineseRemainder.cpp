LL solve(LL x1, LL m1, LL x2, LL m2) {
  LL g = gcd(m1, m2);
  if((x2 - x1) % g) return -1;// no sol
  m1 /= g; m2 /= g;
  int p, q;
  extgcd(m1, m2, p, q);
  LL lcm = m1 * m2 * g;
  LL res = p * (x2 - x1) * m1 + x1;
  return (res % lcm + lcm) % lcm;
}
