/* O(E log V) */
vi taken;
priority_queue<ii> pq;
void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
	}
}
taken.assign(V, 0);
process(0);
mst_cost = 0;
while (!pq.empty()) {
	ii front = pq.top(); pq.pop();
	u = -front.second, w = -front.first;
	if (!taken[u]) mst_cost += w, process(u);
}
printf("MST cost = %d (Prim’s)\n", mst_cost);