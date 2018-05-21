#include <bits/stdc++.h>
using namespace std;
///********************bipartiteness
bool see[11111];
bool col[11111];

bool dfs(int v ,bool f){
	see[v] = 1;
	col[v] = f;
	for(int i =0 ;i<adj[v].size(); i++){
		int u = adj[v][i];
		if(!see[u]){
			bool res = dfs(u,1-f);
			if(res  == 0)return 0;	
		} 
		if(col[u] == f)return 0;
	}
	return 1;
}

int main(){
	dfs(0,0);
}