#include <bits/stdc++.h>
using namespace std;


void topo(int v , bool see[] ,stack <int> &st,vector<int> adj[]){
	see[v]=1;
	for(int i=0;i<adj[v].size();i++){
		if(see[adj[v][i]]==0)topo(adj[v][i],see,st,adj);
	}
	st.push(v);
}

inline bool longestpath(int a){
	memset(see,0,sizeof see);
	vector<int > dis(n+1,-MAX);
	dis[a]=0;
	
	for(int i=1;i<=n;i++){
		if(see[i] == 0)topo(i,see,st,adj);
		
	}
	while(!st.empty()){
		
			int u=st.top();st.pop();
			if(dis[u] == -MAX)continue;
			
			for(int i=0;i<adj[u].size();i++){
				
				if(dis[adj[u][i]] < dis[u] + 1){

					dis[adj[u][i]] = dis[u] + 1;
				}
			}
	}	
}