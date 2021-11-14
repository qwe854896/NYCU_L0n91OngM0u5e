ll f(ll x,ll mod){ return add(mul(x,x,mod),1,mod); }
ll pollard_rho(ll n){
  if(!(n&1)) return 2;
  while(1){
    ll y=2,x=rand()%(n-1)+1,res=1;
    for(int sz=2;res==1;y=x,sz<<=1)
      for(int i=0;i<sz&&res<=1;++i)
        x=f(x,n),res=gcd(abs(x-y),n);
    if(res!=0&&res!=n) return res;
  }
}
// Factorize n
vector<ll> factorize(ll n) {
  vector<ll> ans;
  if (n == 1)
    return ans;
  if (miller_rabin(n)) {
    ans.push_back(n);
  } 
  else {
    ll d = 1;
    while (d == 1)
      d = pollard_rho(n);
    vector<ll> dd = factorize(d);
    ans = factorize(n / d);
    for (int i = 0; i < dd.size(); ++i)
      ans.push_back(dd[i]);
  }
  return ans;
}