#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
using st = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using mp = tree<ll,        ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
 
main()
{
    __gnu_pbds::priority_queue<int> h1, h2; // max heap
    h1.push(1), h1.push(3), h2.push(2), h2.push(4);
    h1.join(h2); // h1 = {1, 2, 3, 4}, h2 = {};

    for (int x : {0, 2, 3, 4}) st.insert(x);
    *st.find_by_order(2); // 3
    st.order_of_key(1); // 1
}
