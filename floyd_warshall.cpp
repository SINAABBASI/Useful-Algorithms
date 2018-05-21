#include <bits/stdc++.h>
using namespace std;
#define inf  100000000 
/*
verctor< pair<int,int> > adj[];
*/
long long  d[100][100];
int path[100][100];
///////////////////////////////////////if graph isnt negative cycle
void floyd(int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( d[i][k] == inf || d[k][j] == inf ) continue;
				if( d[i][j] > d[i][k] + d[k][j] ){
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

}


int main(){
	int a,b,w,m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)d[i][i]=0;
			else d[i][j]=inf;
			}	
	}
	memset(path,-1,sizeof path);

	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		d[a][b]=w;
		path[a][b]=a;
	}	
	floyd(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout<<path[i][j]<<" ";
		cout<<endl;
	}
}