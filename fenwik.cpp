#include <bits/stdc++.h>
using namespace std;

int BITree[];


//////////////////////////////// sum 0 to  i & max 0 to i
int getsum(int index){
	int ans=0;
	//ans = inf;
	index++;
	while(index>0){
		
		ans+=BITree[index];
		// ans = max(ans,BITree[i]);

		index -= index & (-index);
	}
	return ans;
}

void update(int index,int val){
	index++;
	while(index <= MAX){

		BITree[index]+=val;
		//BITree[index] = max(BITree[MAX],val);

		index += index & (-index);
	}
}

////////////////////////////////
int mian(){
	memset(BITree,0,sizeof BITree);
}