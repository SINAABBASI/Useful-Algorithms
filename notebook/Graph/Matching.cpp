bool seen[30];
vector <int> g[30];
vector <int> ml, mr;

bool find_match(int u) {
	if(seen[u]) return 0;
	seen[u] = 1;
	for(int v : g[u]) {
		if(mr[v] == -1) {
			ml[u] = v;
			mr[v] = u;
			return 1;
		}
		if(mr[v] != -1 && find_match(mr[v])) {
			ml[u] = v;
			mr[v] = u;
			return 1;
		}
	}
	return 0;
}
int max_matching() {
	int cnt = 0;
	ml.assign(30, -1);
	mr.assign(30, -1);
	for(int i=0; i<26; i++) {
		memset(seen, 0, sizeof seen);
		if(find_match(i)) cnt++;
	}
	return cnt;
}