#include <bits/stdc++.h>
using namespace std;
#define inf 10001

/*coin changing: minumum coin*/

int main(){
	cin>>n>>sum;
	int sum,n;
	int dp[n][sum+1];
	vector<int> coin(n);
	
	for(int i=0;i<n;i++) cin>>coin[i];
	for(int i=0;i<n;i++) dp[i][0]=0;	
	for(int i=0;i<=sum;i++) dp[0][i]=i;
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=coin[i])
				dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i] ]+1);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<'\n'<<dp[n-1][sum];	
}



/*number of way*/
int main(){
	int n,tol;
	cin>>n>>tol;
	int dp[n][tol+1];
	std::vector<int> coin(n);
	for(int i=0;i<n;i++)cin>>coin[i];
	for(int i=0;i<n;i++) dp[i][0]=1;
	for(int i=1;i<=tol;i++) if(i%coin[0]==0)dp[0][i]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<=tol;j++){
			if(j>=coin[i])
				dp[i][j]=dp[i-1][j]+dp[i][j-coin[i]];
			else 
				dp[i][j]=dp[i-1][j];
		}
	}

	cout<<dp[n-1][tol];	
}