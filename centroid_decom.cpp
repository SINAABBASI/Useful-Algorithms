//In the name of Allah
///////***************centroid decom impleament *** O(nlog n) path***
queue<pair<int,int> > q;
int deleted[MAX],sz[MAX],par[MAX];

void dfs(int u,int p = -1){
	sz[u] = 1;
	for(auto v : g[u]){
		if(v != p && !deleted[v]) dfs(v,u),sz[u] += sz[v];
	}
}

void find_centroid(int u,int p,int siz,int ansec){
	for(auto v : g[u]){
		if(v != p && !deleted[v] && sz[v] > siz) return find_centroid(v,u,siz,ansec);
	}
	
	deleted[u] = 1;
	par[u] = ansec;
	for(auto v : g[u]){
		if(!deleted[v])
			q.push({v,u});
	}

}

void solve(){
	q.push({1,-1});
	while(q.size()){
		int u = q.front().first;
		dfs(u);
		find_centroid(u,-1,sz[u]/2,q.front().second);
		q.pop();
	}
}



///////example : https://codeforces.com/contest/321/problem/C & https://codeforces.com/contest/342/problem/E




