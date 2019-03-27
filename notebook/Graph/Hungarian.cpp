const int M=155;
const int INF=2e9;
int n,cost[M][M],from[M],lx[M],ly[M],slack[M],vx[M],vy[M];
int path(int v){
  int t;
  vx[v]=1;
  for(int i=1;i<=n;i++)
    {
      if(vy[i])continue;
      t=lx[v]+ly[i]-cost[v][i];
      if(t==0)
	{
	  vy[i]=1;
	  if(from[i]==0||path(from[i]))
	    {
	      from[i]=v;
	      return 1;
            }
        }
      else if(t<slack[i])
	slack[i]=t;
    }
  return 0;
}
int hung()
{
  int d,ans=0;
  for(int i=1;i<=n;i++)
    while(true)
      {
	memset(vx,0,sizeof(vx));
	memset(vy,0,sizeof(vy));
	for(int j=1;j<=n;j++)
	  slack[j]=INF;
	if(path(i)) break;
	d=INF;
	for(int j=1;j<=n;j++)
	  if(!vy[j] && slack[j]<d)
	    d=slack[j];
	for(int j=1;j<=n;j++)
	  {
	    if(vx[j])lx[j]-=d;
	    if(vy[j])ly[j]+=d;
	  }
      }
  for(int i=1;i<=n;i++)
    ans+=cost[from[i]][i];//the from meaning...
  return ans;
}
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      {
	cin>>cost[i][j];
	if(cost[i][j]>lx[i])
	  lx[i]=cost[i][j];
      }
  cout<<hung();
}