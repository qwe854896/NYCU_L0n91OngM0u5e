struct INFO {
 int freq;
 int parity;
 int prod;
} info[V];
/* find all coprime pairs */
// [n == 1] = \sum_{d | n} \mu(d)
// substitute n to gcd(i, j)
signed main() {
 // input n
 for (i = 2; i < V; ++i)  // init
  info[i].freq = info[i].parity = 0, info[i].prod = 1;

 for (i = 0; i < n; ++i) cin >> x, ++info[x].freq, M = max(M, x);

 for (i = 2; i * i <= M; ++i)  // preprocess
  if (info[i].prod == 1)
   for (j = i, k = i; j <= M; j += i) {
    if (--k) {
     info[j].parity ^= 1;
     info[j].prod *= i;
    } else {
     info[j].prod = 0;
     k = i;
    }
   }
 for (; i <= M; ++i)
  if (info[i].prod && info[i].prod != i) info[i].parity ^= 1;

 ll ans = (n * (n - 1)) >> 1, c;
 for (i = 2; i <= M; ++i)
  if (info[i].prod) {
   c = 0;
   for (j = i; j <= M; j += i) c += info[j].freq;
   ans -= ((info[i].parity << 1) - 1) * ((c * (c - 1)) >> 1);
  }
}