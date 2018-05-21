#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000000




/////////////************dikstra with priority_queue with display path****************////////////////////



vector<pair<int,int > > adj[1000101];
vector<int> ans;

void dik(int a,int n){
	priority_queue<pair<int,int > ,vector<pair<int,int > > ,greater<pair<int,int > > >pq;
	vector<long long int > dist(n+1,inf);
	pq.push(make_pair(0,a));
	dist[a]=0;
	int parrent[n+1];
	for(int i=0;i<=n;i++)parrent[i]=i;

	while(!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		
		for(int i=0;i<adj[v].size();i++){
			int u=adj[v][i].first;
			int l=adj[v][i].second;
			if(dist[u] > dist[v] + l ){
				dist[u] = dist[v]+ l;
				parrent[u]=v;
				pq.push(make_pair(dist[u],u));
			}
		}
	}
	if(dist[n]==inf)cout<<-1;
	else{
		int i=n;
		while(1){
			ans.push_back(i);
			i=parrent[i];
			if(i==1)break;
		}
		ans.push_back(1);
	}
	
}


///////////////////////////////*O( E log(V) )*//////////////////

int main(){
	ios::sync_with_stdio(0);cin.tie();cout.tie(0);
	int n,m,a,b,w,x,y;
	cin>>n>>m; 
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		if(a == x && b==y){
			adj[a].push_back(make_pair(b,min(w,adj[a][b].second)));
			adj[b].push_back(make_pair(a,min(w,adj[a][b].second)));
		}
		else{
			adj[a].push_back(make_pair(b,w));
			adj[b].push_back(make_pair(a,w));			
		}
		x=a;y=b;
	}
	dik(1,n);
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<< " ";
}