int S;
cin >> S;
vector <int> d(V, INF);
d[S] = 0;
vector <int> par(V, -1);
par[S] = S;
priority_queue < pair <int, int> > pq;
pq.push(make_pair(0, S));
while(pq.size()) {
	pair <int, int> top = pq.top();
	pq.pop();
	if(top.fr > d[top.se]) continue;
	for(int i=0; i<g[top.se].size(); i++) {
		if(d[top.se] + g[top.se][i].se < d[g[top.se][i].fr]) {
			d[g[top.se][i].fr] = d[top.se] + g[top.se][i].se;
			par[g[top.se][i].fr] = top.se;
			pq.push(make_pair(d[g[top.se][i].fr], g[top.se][i].fr));
		}
	}
}
for(int i=0; i<V; i++) cout << i << " " << d[i] << endl;
// print_path(0);
int x = 0;
while(par[x] != x)  {
	cout << x << " ";
	x = par[x];
}
cout << S << endl;