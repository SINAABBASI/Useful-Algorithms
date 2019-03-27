//precompute
void sparse() {
  //st[i][j] = min in range [i , i+2^j]
  for(int j=0;j<MAXLOG;j++)
    for(int i=0;i<n;i++) // 0-base
      if(i+ (1<<j) -1<n) {
        st[i][j]=(j ? min(st[i][j-1],st[i+(1<<j-1)][j-1]) : a[i]);
	       cout<<i<<" "<<j<<" "<<st[i][j]<<endl;
      }
}
int query(int L,int R) {
  int x=0,rem=R-L+1;
  // x=log2(R-L+1);
  while(rem>1)x++,rem>>=1;
  cout<<x<<endl;
  return min( st[L][x],st[R-(1<<x)][x]);
}