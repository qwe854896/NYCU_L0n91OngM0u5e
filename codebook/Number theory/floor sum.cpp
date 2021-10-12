ll q(ll a, ll b) {
	a += b * MOD;
	return a / b - MOD;
}
ll f(ll n, ll m, ll a, ll b) {
	if (!n) return 0;
	if (!a) return b / m * n;
	ll x = (a * (n - 1) + b) / m;
	ll y = a - b - 1;
	ll r = (y % a + a) % a;
	return q(a - b - 1, a) + n * x - q(m * x - b + a - 1, a) - f(x, a, m % a, r) - x * (x - 1) / 2 * (m / a) - (y - r) / a * x; 
}
// sum^{n-1}_0 floor((a * i + b) / m) in log(n + m + a + b)
