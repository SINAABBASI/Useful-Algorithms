int n;
int dist[123456];
int dp[123456][22];
vector <int> adj[123456];
void bfs() {
	memset(dist, 127, sizeof dist);
	dist[1] = 0;
	queue <int> q;
	q.push(1);
	while(q.size()) {
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++) {
			int v = adj[u][i];
			if(dist[v] > dist[u]+1) {
				dp[v][0] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
void calc() {
	bfs();
	dp[1][0] = 1;
	for(int j=1; j<20; j++)
		for(int i=1; i<=n; i++) 
			dp[i][j] = dp[dp[i][j-1]][j-1];
}
int lca(int a, int b) {
	if(dist[a] > dist[b]) swap(a, b);
	int d = dist[b] - dist[a];
	for(int i=0; i<20; i++) if((d&(1<<i)) > 0) b = dp[b][i];
	if(a == b) return a;
	for(int i=19; i>=0; i--) {
		if(dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}
int distance(int u,int v) {
	return dist[u] + dist[v] - 2*dist[lca(u,v)];
}
int get(int a, int b, int c) {
	int l = lca(a, c);
	int x = min(dist[a] - dist[l] + 1, dist[a] - dist[lca(a, b)] + 1);
	int y = max(dist[lca(b, c)] - dist[l], 0);
	return x+y;
}