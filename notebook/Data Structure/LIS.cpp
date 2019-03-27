#define limit 2000000
int M[limit+10];
vector <int> v(limit+10);

int solver(int n) {
	int L = 0;
	for(int i=0; i<n; i++) {
		int lo = 1, hi = L;
		while(lo <= hi) {
			int mid = (lo+hi+1)/2;
			if(v[M[mid]] <= v[i]) lo = mid+1;
			else hi = mid-1;
		}
		M[lo] = i;
		if(lo > L) L = lo;
	}
	return L;
} // ubc dp lis
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, T;
	cin >> n >> T;
	int a[n], cnt[301];
	memset(cnt, 0, sizeof cnt);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int mx = 0;
	for(int i=0; i<301; i++) mx = max(mx, cnt[i]);
	if(n*T < limit) {
		int foo = 0;
for(int i=0; i<T; i++) for(int j=0; j<n; j++) v[foo++] = a[j];
		cout << solver(n*T) << endl;
		return 0;
	}
	int foo = 0, P = (limit/n);
for(int i=0; i<P; i++) for(int j=0; j<n; j++) v[foo++] = a[j];
	cout << solver(n*P) + (T - P)*mx << endl;
	return 0;
}


template <typename T> int lis(const vector<T> &a) {
	vector <T> u;
	for(const T &x : a) {
		auto it = lower_bound(u.begin(), u.end(), x);
		if(it == u.end()) u.push_back(x);
		else *it = x;
	}
	return (int) u.size();
}