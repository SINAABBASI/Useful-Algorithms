struct Complex {
	ldouble x, y;
	Complex() {}
	Complex(ldouble x, ldouble y) : x(x), y(y) {}
	Complex(const Complex &P) : x(P.x), y(P.y) {}
	Complex operator + (const Complex &P) const {
		return Complex(x + P.x, y + P.y);
	}
	Complex operator - (const Complex &P) const {
		return Complex(x - P.x, y - P.y);
	}
	Complex operator * (Complex c) const {
		return Complex(x*c.x - y*c.y, x*c.y + y*c.x);
	}
	Complex operator / (ldouble c) const {
		return Complex(x/c, y/c);
	}
	ldouble real() {
		return x;
	}
	ldouble imag() {
		return y;
	}
};
inline int get_degree(int t) {
	for(int i=0; ; i++) if(t < (1<<i)) return (1<<i);
}
int reverse(int num, int lg_n) {
	int res = 0;
	for(int i = 0; i < lg_n; i++) if(num & (1 << i)) res |= 1 << (lg_n - 1 - i);
	return res;
}
void fft(vector<Complex> &a, bool inv) {
	int n = a.size();
	int lg_n = 0;
	while((1 << lg_n) < n) lg_n++;
	for(int i = 0; i < n; i++) if(i < reverse(i, lg_n)) swap(a[i], a[reverse(i, lg_n)]);
	for(int len = 2; len <= n; len <<= 1) {
		ldouble ang = 2 * PI / len * (inv ? -1 : 1);
		Complex wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len) {
			Complex w(1, 0);
			for(int j = 0; j < len / 2; j++) {
				Complex u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w = w * wlen;
			}
		}
	}
	if(inv) for(Complex &x : a) x.x /= n;
}
void multiply(vector <ll> &a, vector <ll> &b) {
	int n = sz(a)-1;
	int m = sz(b)-1;
	int d = get_degree(n+m+1);
	vector <Complex> P(d, Complex(0, 0));
	vector <Complex> Q(d, Complex(0, 0));
	for(int i=0; i<=n; i++) P[i].x = a[i];
	for(int i=0; i<=n; i++) Q[i].x = b[i];
	fft(P, 0);
	fft(Q, 0);
	for(int i=0; i<d; i++) P[i] = P[i] * Q[i];
	fft(P, 1);
	a.resize(n+m+1);
	for(int i=0; i<=n+m; i++) a[i] = ((ll) (P[i].x + 0.5));
}