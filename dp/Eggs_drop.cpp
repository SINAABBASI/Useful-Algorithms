#include <bits/stdc++.h>
#include <string>
using namespace std;
#define fr first
#define sc second
#define inf 10000001


int main(){
	int flowr,mx,egg;
	cin>>flowr >>egg;
	int dp[egg+1][flowr+1];
	memset(dp,0,sizeof dp);
	for(int i=1;i<=flowr;i++) dp[1][i]=i;

	for(int i=2;i<=egg;i++){
		for(int j=1;j<=flowr;j++){
			if(i>j) 
				dp[i][j]=dp[i-1][j];
			else{
				int mn=inf;
				for(int k=1;k<=j;k++){
					mx=1+max(dp[i-1][k-1],dp[i][j-k]);
					mn=min(mn,mx);
				}
				dp[i][j]=mn;
			}
		}
	}
	cout<<dp[egg][flowr];
}