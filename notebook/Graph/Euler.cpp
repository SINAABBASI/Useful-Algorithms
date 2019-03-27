/* O(E log n) */

map < int, int > mp[maxN];

void dfs(int v) {
	for(int i=0; i < g[v].size(); i++) {
		if(mp[v][g[v][i]]) {
		mp[v][g[v][i]]--;
		mp[g[v][i]][v]--;
		int u=g[v][i];
		dfs(u);
		}
	}
	cout << v << " ";
}
// ---> second way <---
list<int> cyc;

void EulerTour(list<int>::iterator i, int u) {
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (v.second) {
			v.second = 0;
			for (int k = 0; k < (int)AdjList[v.first].size(); k++) {
				ii uu = AdjList[v.first][k];
				if (uu.first == u && uu.second) {
					uu.second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(i, u), v.first);
		}
	}
}
// inside int main()
cyc.clear();
EulerTour(cyc.begin(), A);
for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++)
	printf("%d\n", *it);