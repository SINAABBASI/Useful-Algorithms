void compute(int l, int r, int optl, int optr) {
  if(l > r) return;
  int mid = (l + r) >> 1;
  pair <int, int> best = {2*inf, -1};
  for(int i=optl; i<=min(mid, optr); i++)
    best = min(best, {dp_bef[i-1] + dp[i][mid], i});
  dp_cur[mid] = best.fr;
  int opt = best.se;
  compute(l, mid-1, optl, opt);
  compute(mid+1, r, opt, optr);
}

int main() {
  init(); // init dp ---> cost-function
	dp_cur[0] = inf;
	for(int i=1; i<=n; i++) dp_cur[i] = dp[1][i];
	for(int j=2; j<=k; j++) {
		dp_bef = dp_cur;
		compute(1, n, 1, n);
	}
	cout << dp_cur[n] << endl;
	return 0;
}