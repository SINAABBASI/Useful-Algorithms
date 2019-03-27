#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1000000000000000
#define ll long long
#define MAX  300011 
#define endl '\n'
#define fr first	
#define sc second


/////////////************dikstra with priority_queue with display path****************////////////////////
//////////////worked with multiple edge

int n,m,k;
int id[MAX],par[MAX];
ll dis[MAX];
struct ver
{
	int v,id,w;	
}temp;
vector<ver> g[MAX];
bool see[MAX];
inline void dik(){
	priority_queue<pair<ll,int> > pq;
	pq.push({0,1});
	for(int i = 1; i <= n ; i++)dis[i] = inf;
	dis[1] = 0;
	int u,v,w;
	while(pq.size()){
		u = pq.top().sc;
		pq.pop();
		// if(see[u])continue; JUST USING FOR CREATE A DIKESTRA TREEE
		// see[u] = 1;
		for(auto i : g[u]){
			v = i.v;w  = i.w;
			if(dis[v] > dis[u] + w){
				par[v] = u;
				dis[v] = dis[u] + w;
				id[v] = i.id;
				
				pq.push({-dis[v],v});
			}
		}
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