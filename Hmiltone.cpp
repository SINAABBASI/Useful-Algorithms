											/*In the name of ALLAH*/
											/*Hamilton path*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int n,m,a,b;

bool hamilton(int pos,int path[] , bool see[]){
	if(pos == n+1 )return 1;//////if we have hamilton path if we have correct path with lenght n 
	for(int i=0 ; i< adj[path[pos-1]].size() ;i++){
		
		int u=adj[path[pos-1]][i];
		if(see[u] == 0){////////// if u is not include path
			see[u] = 1;
			path[pos] = u;
			if(hamilton(pos+1 , path , see ) )return 1;
			path[pos] = -1;//////// if we have not correct path we have remove it for answer
			see[u] = 0;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		bool see[1000],ans=0;
		int path[1000];
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i = 1; i <= n ; i++){
			memset(path,-1,sizeof path);
			memset(see,0,sizeof see);
			see[i]=1;
			path[1]=i;
			if(hamilton(2,path,see)){
				ans = 1;
				break;
			}
		}
		cout<<ans<<'\n';
		for(int i=0;i<1000;i++)adj[i].clear();
	}
	return 0;
}
