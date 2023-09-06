#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>,                   // set type
             null_type, less<pair<int, int>>,  // set type cmp
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;

signed main() {
 int n;
 int sz = 0;
 cin >> n;
 vector<int> ans(n, 0);

 ordered_set t;
 int x, y;
 for (int i = 0; i < n; i++) {
  cin >> x >> y;
  ans[t.order_of_key({x, ++sz})]++;
  t.insert({x, sz});
 }

 for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

/***
Input
5
1 1
5 1
7 1
3 3
5 5

Output
1
2
1
1
0
***/
