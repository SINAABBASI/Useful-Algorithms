class SegmentTree {
private:
	vector <long long> tree;
	long long lazy[10*max_n];
	void build(int node, int start, int end) {
		if(start == end) tree[node] = A[start];
		else {
			int mid = (start + end) / 2;
			build(2*node, start, mid);
			build(2*node+1, mid+1, end);
			tree[node] = tree[2*node] + tree[2*node+1];
		}
	}
	void updateRange(int node, int start, int end, int l, int r, long long val) {
		if(lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if(start != end) {
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > end || start > r || end < l) return;
		if(start >= l && end <= r) {
			tree[node] += (end - start + 1) * val;
			if(start != end) {
				lazy[node*2] += val;
				lazy[node*2+1] += val;
			}
			return;
		}
		int mid = (start + end) / 2;
		updateRange(node*2, start, mid, l, r, val);
		updateRange(node*2 + 1, mid + 1, end, l, r, val);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	long long queryRange(int node, int start, int end, int l, int r) {
		if(start > end || start > r || end < l) return 0;
		if(lazy[node] != 0) {
				tree[node] += (end - start + 1) * lazy[node];
			if(start != end) {
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start >= l && end <= r) return tree[node];
		int mid = (start + end) / 2;
		long long p1 = queryRange(node*2, start, mid, l, r);
		long long p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
		return (p1 + p2);
	}
public:
	int n;
	vector <long long > A;
	SegmentTree() {}
	SegmentTree(const vector <long long> &v) {
		A = v;
		n = A.size();
		tree.assign(5*n, 0);
		memset(lazy, 0, sizeof lazy);
		build(1, 0, n-1);
	}
	long long query(int l, int r) {
		return queryRange(1, 0, n-1, l, r);
	}
	void update(int l, int r, long long val) {
		updateRange(1, 0, n-1, l, r, val);
	}
};