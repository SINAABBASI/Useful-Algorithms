struct Point {
	int id;
	long long  x, y;
	Point() {}
	bool operator < (const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	long long dist(pair <long long, long long> b) {
		return (x - b.second) * (x - b.second) + (y - b.first) * (y - b.first);
	}
};

int main() {
	int n;
	cin >> n;
	vector <Point> p(n);
	for(int i=0; i<n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p.begin(), p.end());
	long long ans = inf;
	int I = 0, J = 1;
	set < pair < pair <long long, long long>, int> > st;
	st.insert(make_pair(make_pair(p[0].y, p[0].x), p[0].id));
	int now = 0;
	for(int i=1; i<n; i++) {
		long long foo = (long long) (sqrt(ans)) + 1;
		for(int k=now; k<i; k++) {
			if(p[i].x - p[k].x <= foo) break;
			st.erase( make_pair( make_pair( p[k].y, p[k].x ), p[k].id ) );
			now = k+1;
		}
		auto start = lower_bound(st.begin(), st.end(), make_pair( make_pair(p[i].y - foo, -inf), 0 ) );
		auto end = upper_bound(st.begin(), st.end(), make_pair( make_pair(p[i].y + foo, inf), 0 ) );
		while(start != end) {
			long long bar = p[i].dist((*start).first);
			if(ans > bar) {
				ans = bar;
				I = (*start).second;
				J = p[i].id;
			}
			start++;
		}
		st.insert(make_pair(make_pair(p[i].y, p[i].x), p[i].id));
	}
	cout << min(I, J) << " " << max(I, J) << " " << fixed << setprecision(6) << sqrt(ans) << endl;
	return 0;
}