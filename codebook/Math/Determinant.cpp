template<class T>
T det()
{
  T x=1;
  for(int i=0;i<n;++i)
  {
    int mxl=i;
    for(int j=i+1;j<n;++j)
      if(M[j][i]>M[mxl][i]) mxl=j;
    if(mxl!=i)
      M[i].swap(M[mxl]),x*=-1;
    if(M[i][i] == 0) return 0;
    for(int j=i+1;j<n;++j)
    {
      T tmp=-M[j][i]/M[i][i];
      for(int k=i;k<m;++k)
        M[j][k]+=tmp*M[i][k];
    }
  }
  for(int i=0;i<n;++i)
    x=x*M[i][i];
  return x;
}
