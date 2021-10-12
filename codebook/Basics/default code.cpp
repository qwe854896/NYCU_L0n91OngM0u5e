#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb emplace_back
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, y) memset(x, y, sizeof(x))
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += (begin > end ? -1 : 1))
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

using ll  = long long;
using vi  = vector <int>;
using vii = vector <vi>;
using pii = pair <int, int>;
using pll = pair <ll , ll >;

const int MOD = 1000000007;
const ll INF = 0x7f7f7f7f7f7f7f7f; // 922337203685477580;

signed main () {
//	IOS;
}