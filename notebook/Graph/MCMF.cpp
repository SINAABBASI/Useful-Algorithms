struct edge {
	int a, b;
	ll cap, cost;
};
 
vector <edge> e;
vector <int> g[max_n];

void add_edge(int a, int b, int cap, ll cost) {
	edge e1 = { a, b, cap, cost };
	edge e2 = { b, a, 0, -cost };
	g[a].push_back(sz(e));
	e.push_back(e1);
	g[b].push_back(sz(e));
	e.push_back(e2);
}
// dijkstra or bellman-fored
void shortest_paths(int n, int v0, vector <ll> &d, vector <int> &p) {
	d.assign(n, inf);
	d[v0] = 0;
	deque <int> q;
	q.push_back(v0);
	p.assign(n, -1);
	vector <int> m(n, 2);
	while(sz(q)) {
		int u = q.front();
		q.pop_front();
		m[u] = 0;
		for(int i : g[u]) {
			int v = e[i].b;
			if(e[i].cap > 0 && d[v] > d[u] + e[i].cost) {
				d[v] = d[u] + e[i].cost;
				p[v] = i;
				if(m[v] == 2) {
					m[v] = 1;
					q.push_back(v);
				}
				else if(m[v] == 0) {
					m[v] = 1;
					q.push_front(v);
				}
			}
		}
	}
}
pair <ll, ll> min_cost_flow(int n, int needed_flow, int s, int t) {
	int flow = 0;
	ll cost = 0;
	vector <int> p;
	vector <ll> d;
	while(flow < needed_flow) {
		shortest_paths(n, s, d, p);
		if(d[t] > 5e8) break;
		ll f = needed_flow - flow;
		ll cur = t;
		while(cur != s) {
			f = min(f, e[p[cur]].cap);
			cur = e[p[cur]].a;
		}
		flow += f;
		cost += f * d[t];
		cur = t;
		while(cur != s) {
			e[p[cur]].cap -= f;
			e[p[cur]^1].cap += f;
			cur = e[p[cur]].a;
		}
	}
	return {flow, cost};
}

int cnt[555];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--) {
		e.clear();
		for(int i=0; i<max_n; i++) g[i].clear();
		int n, x, y;
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for(int i=0; i<n; i++) {
			cin >> x;
			cnt[x]++;
		}
		for(int i=1; i<=n; i++) {
			add_edge(0, i, cnt[i], 0);
			add_edge(i, n+1, 1, 0);
		}
		int q;
		cin >> q;
		while(q--) {
			cin >> x >> y;
			add_edge(x, y, inf, 1);
			add_edge(y, x, inf, 1);
		}
		auto mcmf = min_cost_flow(n+2, n, 0, n+1);
		assert(n == mcmf.fr);
		cout << mcmf.se << endl;
	}
	return 0;
}