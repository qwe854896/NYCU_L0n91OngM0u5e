/*
我認為可以留這部分就好 :

#include <ext/rope> //header with rope
using namespace __gnu_cxx; //namespace with rope and some additional stuff

rope<int> x, y; int s, len;

x.size(),    x.push_back(s),    x.substr(pos, s)    x[i] 一般功能

x.insert(pos, s or y)
x.erase(pos, len)  刪除[pos, pos + len)
x.replace(pos, s) 將x[pos] 改成 s
x.copy(pos, len, y) 複製[pos, pos + len) 到 y
*/

#include <iostream>
#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

int main()
{
    ios_base::sync_with_stdio(false);
    rope <int> v; //use as usual STL container
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        v.push_back(i); //initialization
    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        rope <int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);
    }
    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it)
        cout << *it << " ";
    return 0;
}