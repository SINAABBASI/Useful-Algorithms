#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int edit[s1.size()+1][s2.size()+1];
	memset(edit,0,sizeof edit);
	for(int i=1;i<=s1.size();i++)
		edit[i][0]=i;
	for(int i=1;i<=s2.size();i++)
		edit[0][i]=i;
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1])
				edit[i][j]=edit[i-1][j-1];
			else {
				edit[i][j]=min(edit[i-1][j],min(edit[i][j-1],edit[j-1][i-1]) )+1;
			}
		}
	}
	cout<<edit[s1.size()][s2.size()];
}	