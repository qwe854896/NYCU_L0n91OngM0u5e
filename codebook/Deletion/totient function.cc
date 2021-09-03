const int MN = 1e6 + 5;
int E[MN];
void Init(){
  for(int i = 1;i < MN; i++){
    E[i] = i;
  }
  for(int i = 1; i < MN; i++){
    for(int x = (i << 1); x < MN; x += i){
      E[x] -= E[i];
    }
  }
}