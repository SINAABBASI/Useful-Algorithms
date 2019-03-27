#define max_logn 23
#define max_n 1234567
int n;
string s;
int R[max_logn][max_n];

void make_suffix_array() {
	for(int i=0; i<n; i++) R[0][i] = s[i];
	pair < pair <int, int> , int > T[n];
	int lvl = 1, skip = 1;
	while(skip < n) {
	for(int i=0; i<n; i++) T[i] = {{R[lvl-1][i], R[lvl-1][i+skip]}, i};
		sort(T, T+n);
		for(int i=0; i<n; i++) {
		if(i > 0 && T[i].first == T[i-1].first) R[lvl][T[i]._2] = R[lvl][T[i-1]._2]
			else R[lvl][T[i]._2] = i
		}
		skip *= 2;
		lvl++;
	}
	return r;
}

// ========================= SA second ==========================
#define fr first
#define se second.first
#define th second.second
#define max_n 100000 // = sizeof string A
#define max_log_n 20 // = [lg(max_n)] (ceil)

string A;
int n, stp, cnt;
int P[max_log_n][max_n];
pair < int, pair <int, int> > L[max_n];

int suffix_array() {
	int n = A.size(), stp = 1;
	for(int i = 0; i < n; i++) P[0][i] = A[i] - 'a';
	for(int cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
		for(int i = 0; i < n; i++) {
			L[i].fr=P[stp - 1][i];
			L[i].se=(i + cnt < n) ? P[stp - 1][i + cnt]: -1;
			L[i].th = i;
		}
		sort(L, L + n);
		for(int i = 0; i < n; i++) P[stp][L[i].th] = ( i > 0 && L[i].fr == L[i - 1].fr && L[i].se == L[i - 1].se ) ? P[stp][L[i - 1].th] : i;
	}
	return stp-1;
}

int main() {
	cin >> A;
	int tmp = suffix_array();
	for(int i=0; i<A.size(); i++) cout << P[tmp][i];
	return 0;
}