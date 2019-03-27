class BIT {
	public :
	int tree[max_n];
	BIT() { memset(tree, 0, sizeof tree); }
	int query(int idx) {
		int sum = 0;
		while (idx > 0){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	int query(int i, int j) {
		return query(j) - query(i-1);
	}
	void update(int idx, int val) {
		while (idx <= max_n) {
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
}
///***temp
struct FenwickTree {
	int n;
	vector<ll> t;
	FenwickTree(int nn) {
		n = nn;
		t.resize(n + 1);
	}
	void inc(int pos, ll delta) {
		pos++;
		while (pos <= n) {
			t[pos] += delta;
			pos += pos & -pos;
		}
	}
	ll sum(int r) {
		r++;
		ll res = 0;
		while (r > 0) {
			res += t[r];
			r -= r & -r;
		}
		return res;
	}
	int firstIndexOfGE(ll val) {
		int step = (1 << 19);
		int i = 0;
		ll now = 0;
		while (step > 0) {
			if (i + step <= n && now + t[i + step] < val) {
				now += t[i + step];
				i += step;
			}
			step /= 2;
		}
		return i; // 1-indexed fenwick
	}
	void debug() {
		for (int i = 0; i < n; i++) {
			cerr << sum(i) - sum(i - 1) << ' ';
		}
		cerr << endl;
	}
};
///****