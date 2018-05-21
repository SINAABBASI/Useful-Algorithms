														/******In the name of ALLAH*********/
#include <bits/stdc++.h>
using namespace std;
#define pp make_pair
#define MAX 1001101
///////////deleting edge
vector <int > adj[MAX];
bool at[MAX]={0},del[MAX]={0};
bool dfs(int v){
	see[v] =1;
	bool flag = 0;
	for(int i =0 ; i< adj[v].size() ; i++){
		int u = adj[v][i];
		if(!see[u] ){
			if(dfs(u) == true)
				flag = 1;	
		} 
	}
	if(at[v]) {
		del[v] =  0;
		return 1;
	}
	del[v] = not(flag) ;
	return flag;
}
