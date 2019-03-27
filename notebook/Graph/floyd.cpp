// i -> ... -> p[i][j] -> j
for (int i = 0; i < V; i++)
for (int j = 0; j < V; j++)
p[i][j] = i;
for (int k = 0; k < V; k++)
for (int i = 0; i < V; i++)
for (int j = 0; j < V; j++)
if (g[i][k] + g[k][j] < g[i][j]) {
	g[i][j] = g[i][k] + g[k][j];
	p[i][j] = p[k][j];
}
void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	printf(" %d", j);
}