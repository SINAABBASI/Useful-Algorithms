#include <bits/stdc++.h>
using namespace std;
vector<int> g[MAX],_g[MAX];
stack<int> st;
bool see[MAX];

void dfs(int u){
  see[u] = 1;
  for(auto v: g[u]){
    if(!see[v])dfs(v);
  }
  st.push(v);
}

void dfs_back(int u){
  cout<<u+1<< " " ;
  see[u] = 1;
  for(auto v : _g[u])
    if(!see[v])dfs_back(v);
}

void find_comp(){
  memset(see,0,sizeof see);
  int copms = 0 ;
  for(int i=0 ;i< n ; i++)
    if(!see[i])dfs(i);
  memset(see,0,sizeof see);
  while(!st.empty()){
    int v =st.top();
    st.pop();
    if(!see[v]){
      cout<<++copms<<" : ";
      dfs_back(v);
      cout<<endl;
    }
  }
}