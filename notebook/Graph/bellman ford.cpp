/* O(VE) */
vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++)
for (int u = 0; u < V; u++)
for (int j = 0; j < g[u].size(); j++) {
	ii v = g[u][j];
	dist[v.first] = min(dist[v.first], dist[u] + v.second);
}
// if there is one more relax-able adge then we have negetive cycle