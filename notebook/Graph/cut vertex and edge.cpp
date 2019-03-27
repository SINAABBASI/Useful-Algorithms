int dfs(int v,int par,int h){
  int up=h,cnt=0;
  mark[v]=true;
  H[v]=h;
  for(auto u:g[v]){
    if(!mark[u]){
      cnt++;
      int d=dfs(u,v,h+1);
      up=min(up,d);
      if(d>=h)cv[v]=true;
      //cut edge: d>h -> (u,v) is cut edge
    }
    else if(u!=par) up=min(up,H[u]);
  }
  if(v==1){
    if(cnt > 1) cv[v]=true;
    else cv[v]=false;
  }
  return up;
}