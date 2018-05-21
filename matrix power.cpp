
long long f[2][2];
long long one[2][2]={{1,1},{1,0}};

void mul(long long M[2][2]){
	long long x = ( f[0][0]*M[0][0] ) % mod + (f[0][1]*M[1][0]) % mod;
	long long y = ( f[0][0]*M[0][1] ) % mod + (f[0][1]*M[1][1]) % mod;
	long long z = ( f[1][0]*M[0][0] ) % mod + (f[1][1]*M[1][0]) % mod;
	long long w = ( f[1][0]*M[0][1] ) % mod + (f[1][1]*M[1][1]) % mod;

	f[0][0] = x % mod;
	f[0][1] = y % mod;
	f[1][0] = z % mod;
	f[1][1] = w % mod;
}
void mpow(long long n){
	if(n == 0 || n == 1)return;	
	mpow(n/2);
	mul(f);
	if(n & 1){
		mul(one);
	}
}