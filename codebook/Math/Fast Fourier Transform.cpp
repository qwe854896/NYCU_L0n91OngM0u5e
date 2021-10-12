template<int MAXN>
struct FFT {
  using c_t = complex<double>;
  const double PI = acos(-1);
  c_t w[MAXN];
  FFT() {
    double arg = 2 * PI / MAXN;
		c_t delta = c_t(cos(arg), sin(arg));
    w[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
      w[i] = w[i-1] * delta;
    }
  }
  void fft(c_t *a, int n, bool inv=false); // see NTT
  // remember to replace ll with c_t
};
