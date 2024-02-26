/* partial matching list */
string s;
int len=s.length(),list[len]={0};
for(int i=1;i<len;i++) {
  int j=list[i-1];
  while(j>0&&s[i]!=s[j])
    j=list[j-1];
  if(s[i]==s[j])list[i]=j+1;
}

/* finding substring by list */
string p;
int j=0;
bool ans=false;
for(int i=0;i<p.length();i++) {
  if(p[i]==s[j]) {
    j++;
    if(j==len) {
      ans=true;
      break;
    }
  }
  else {
    while(j>0&&p[i]!=s[j])
      j=list[j-1];
    if(p[i]==s[j]) ++j;
    else j = ;
    if(len-j>s.length()-i-1)break;  // small optimization
  }
}