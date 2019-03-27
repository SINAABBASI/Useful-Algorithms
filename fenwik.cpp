#include <bits/stdc++.h>
using namespace std;

int BITree[];


//////////////////////////////// sum 0 to i & max 0 to i
int getsum(int i){
	int ans=0;
	//ans = inf;
	i++;
	while(i>0){
		ans+=BITree[i];
		// ans = max(ans,BITree[i]);
		i -= i & (-i);
	}
	return ans;
}

void update(int i,int val){
	i++;
	while(i <= MAX){

		BITree[i]+=val;
		//BITree[i] = max(BITree[MAX],val);

		i += i & (-i);
	}
}
////////////////////////////////
