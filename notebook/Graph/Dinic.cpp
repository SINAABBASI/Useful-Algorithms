struct edge {
	int a, b, cap, flow;
};

int s, t;
vector <edge> e;
vector <int> g[max_n];
int d[max_n], ptr[max_n];

void add_edge(int a, int b, int cap) {
	edge e1 = {a, b, cap, 0};
	edge e2 = {b, a, 0, 0};
	g[a].push_back(e.size());
	e.push_back(e1);
	g[b].push_back(e.size());
	e.push_back(e2);
}
bool bfs() {
	queue <int> qu;
	qu.push(s);
	memset(d, -1, sizeof d);
	d[s] = 0;
	while(qu.size()) {
		int u = qu.front();
		qu.pop();
		for(int i=0; i<g[u].size(); i++) {
			int id = g[u][i];
			int v = e[id].b;
			if(e[id].cap == e[id].flow) continue;
			if(d[v] != -1) continue;
			d[v] = d[u]+1;
			qu.push(v);
		}
	}
	return (d[t] != -1);
}
int dfs(int u, int flow) {
	if(u == t || flow == 0) return flow;
	for(; ptr[u] < g[u].size(); ptr[u]++) {
		int id = g[u][ptr[u]];
		int v = e[id].b;
		if(d[v] != d[u]+1) continue;
		int pushed = dfs(v, min(flow, e[id].cap-e[id].flow));
		if(pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
int dinic() {
	int flow = 0;
	while(bfs()) {
		memset(ptr, 0, sizeof ptr);
		while(true) {
			int pushed = dfs(s, inf);
			if(pushed == 0) break;
			flow += pushed;
		}
	}
	return flow;
}
int solve(int k) {
	e.clear();
	for(int i=0; i<m+n+7; i++) g[i].clear();
	s = 0;
	t = n + m + 1;
	// add_edge();
	return dinic();
}
// if(e[i].a >= 1 && e[i].a <= n && e[i].flow == 1)