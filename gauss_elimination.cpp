#include <bits/stdc++.h> 
#define MAX 500001
#define inf 100000001
using namespace std;
long long a[MAX];	
int len(long long n){
	int cnt = 0;
	while(n){
		n = n >> 1;
		cnt++;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		vector<long long> b[66];

		for(int i =0 ; i < n ; i++){
			cin>>a[i];
			b[len(a[i])].push_back(a[i]);
		}
		long long modify[66];
		int c = 0;

		for(int i = 65 ;i > 0 ; i--){
			if(b[i].size()){
				modify[c++] = b[i][0];
				for(int j = 1 ; j  < b[i].size(); j++){
					long long temp = b[i][j] ^ b[i][0];
					b[len(temp)].push_back(temp);
				}
			}
		}

		long long ans = k;
		for(int i = 0; i < c; i++) {
			ans = max(ans, ans ^ modify[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}