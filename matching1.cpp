#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define ll long long
#define MAX 11111
int n,m;
bool seen[MAX];
bool seen1[MAX];
int match_R[MAX];
int match_L[MAX];
vector<int> v;
vector< vector<int> > Adj(MAX);
bool bpm(int i){
	for(int j=0;j<Adj[i].size();j++){
		int sir=Adj[i][j];
			if(!seen[sir]){
				seen[sir]=1;
				if( match_R[sir] < 0 || bpm( match_R[sir] )  ){
					match_R[sir]=i;
					match_L[i]=sir;
					return true;
				}
			}
	}
	return false;
}

int Maxbpm(){
	int Max=0;
	memset(match_R , -1 , sizeof match_R);
	memset(match_L , -1 , sizeof match_L);
	for(int i=0;i<m;i++){
		memset(seen,0,sizeof seen);
		if(bpm(v[i]))Max++;
	}
	return Max;
}
int main(){
	cin>>n;
	cin>>m;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0)continue;	
		Adj[i].push_back(a);
		Adj[a].push_back(i);
	}
	for(int i=0;i<m;i++) {
		cin>>a;
		v.push_back(a);
	}
	int ans=Maxbpm();
	for(int i=1;i<MAX;i++){
		if(match_R[i] == i)ans--;
	}

	cout<<ans;
}
