#include <bits/stdc++.h>
using namespace std;
vector<int> adj[max];
stack<int> st;
bool see[max];

void dfs(int v){
	see[v] = 1;
	for(int i =0 ;i <adj[v].size(); i++){
		int u = adj[v][i];
		if(!see[u])dfs(u);
	}
	st.push(v);
}

void dfs_back(int v){
	cout<<v+1<< " " ;
	see[v] = 1;
	for(int i =0 ;i<adj[v].size() ; i++)
		if(!see[adj[v][i]])dfs_back(adj[v][i]);
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

