#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	long long  dp[s.size()][s.size()];
	memset(dp,0,sizeof dp);
	/*l=0*/
	for(long long i=0;i<s.size();i++) dp[i][i]=1;
	
	/*l=1 to s.size()*/
	for(long long l=1;l<s.size();l++){
		for(long long i=0;i<s.size();i++){
			long long j=l+i;
			if(j>=s.size())break;
			else if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		}
	}

	/*Display:

	for(long long i=0;i<s.size();i++){
		for(long long j=0;j<s.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
*/

	cout<<dp[0][s.size()-1];
	return 0;
}