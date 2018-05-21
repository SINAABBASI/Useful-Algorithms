#include <bits/stdc++.h>
using namespace std;

vector<int> adj[111111];
bool end[11111];
bool see[11111];
stack < int > s;


////find cycle in graph
bool dfs(int v){
	see[v]=1;
	for(int i =0 ;i <adj[v].size(); i++){
		int u =adj[v][i];
		if(!see[u])dfs(u);
		if(end[u] == false)return 0;
	}
	end[v] = 1;
	st.push(v);
	return 1;
}

bool topo(){
	memset(see,0,sizeof see);
	memset(end,0,sizeof end);
	for(int i =0 ;i < n; i++)
		if(!see[u] && !dfs(i))return 0;
	return 1;
}



int main(){
	if(topo()){
		while(!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	else
		cout<<-1;
}