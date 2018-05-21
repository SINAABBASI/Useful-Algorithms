#include <bits/stdc++.h>
using namespace std;
#define pair<int,int> pp;
#define inf 100000000000
int dist[max];
vector<pp> edge;
int w[max];

void belman(int s){
	dist[s] = 0 ;
	for(int i = 0; i < n ; i++)if(i!=s)dist[i]=inf;

	for(int i =0 ;i < n-1 ;i ++){
		for(int j = 0; j <edge.size() ; j++){
			int v = edge.first;
			int u = edge.second;
			dist[u] = min(dist[u] , dist[v] + w[j]);
		}
	}
}
int main(){
	belman(0);
}