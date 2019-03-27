// lca part

int DP[LOG][MAX], level[MAX], MX[LOG][MAX];

void _dfs(int u){
  for(auto vv : g[u]){
    int v = vv.first;
      if(DP[0][u] != v){
        DP[0][v] = u;
        // MX[0][v] = vv.second;
        level[v] = level[u] + 1;
        _dfs(v);
      }
  }
}
void preprocess(){
  // One Base Graph
  level[1] = 0;
  DP[0][1] = 0;
  // MX[0][1] = 0;
  _dfs(1);
  for(int i = 1 ; i < LOG ; i++)
    for(int j = 1; j <= n; j++){
      DP[i][j] = DP[i-1][DP[i-1][j]];
      // MX[i][j] = max(MX[i-1][j], MX[i-1][DP[i-1][j]]);
    }
}
int lca(int a,int b){
  // b is greater
  // int ret = 0;
  if(level[a] > level[b])swap(a,b);
  int d = level[b] - level[a];
  for(int i = 0; i < LOG ;i ++){
    if(d & (1<<i)){
      // ret = max(ret,MX[i][b]);
      b = DP[i][b];
    }
  }
  if(a==b)return a//ret;
  for(int i= LOG - 1 ; i >=0 ; i--){
    if(DP[i][a] != DP[i][b]){
      // ret = max(max(ret,MX[i][a]), MX[i][b]);
      a = DP[i][a];
      b = DP[i][b];
    }
  }
  return DP[0][a];
  // ret = max(max(ret,MX[0][a]), MX[0][b]);
  // return ret;
}