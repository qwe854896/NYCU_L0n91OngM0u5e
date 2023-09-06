ll solve(ll x1, ll m1, ll x2, ll m2) {
 ll p, q, g;
 extgcd(m1, m2, p, q, g);
 if ((x2 - x1) % g) return -1;  // no sol
 m1 /= g;
 m2 /= g;
 ll lcm = m1 * m2 * g;
 ll res = p * (x2 - x1) * m1 + x1;
 return (res % lcm + lcm) % lcm;
}
