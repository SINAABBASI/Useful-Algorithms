/*In The Name of ALLAH*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;




int prime[100001];
vector<int> pdiv[100001],tdiv[100001];


void divisor(){
	pdiv[2].push_back(1);
	pdiv[2].push_back(2);
	pdiv[1].push_back(1);
	for(int i = 3 ; i <= 100000 ; i++){
		pdiv[i].push_back(1);
		
		////divisor < sqrt(i)
		for(int j =2; j*j <= i ; j++){
			if(i % j == 0)
				pdiv[i].push_back(j);
		}


		////remain divisor >  sqrt(i)
		tdiv[i] = pdiv[i];
		for(int j = 0; j < tdiv[i].size() ; j++){
			pdiv[i].push_back(i/tdiv[i][j]);
		}
		sort(pdiv[i].begin(), pdiv[i].end());
		vector<int>::iterator it;
		it = unique(pdiv[i].begin(), pdiv[i].end());
		pdiv[i].resize( distance(pdiv[i].begin(),it) );
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	divisor();
	return 0;
}