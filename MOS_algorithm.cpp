											/*In the name of ALLAH*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1555
/**********************sqrt decomposition*********************/

int  a[100002],ans[100002],n,t,cur = 0;
unordered_map <int,int > cnt;
struct q
{
	int L;
	int R;
	int ind;
}qu[100002];

inline bool mo_cmp(q &x,q &y){
	int block_x = x.L / blocksize;
	int block_y = y.L / blocksize;
	if(block_x != block_y)
		return block_x < block_y;
	return x.R < y.R;
}


/*Choosing a way to achieve appropriate time bound O(F) is 
programmer’s main concern when solving problems using Mo’s algorithm.*/
/*O(F) to be O(1) or O(log(n))*/
inline void add(int x){
	int temp = cnt[x];
	if(temp == x )cur--;
	else if(temp == x-1)cur++;
	cnt[x]++;
	return;
}
inline void rem(int  x){
	int temp = cnt[x];
	if(temp == x)cur--;
	else if(temp == x + 1)cur++;
	cnt[x]--;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>t;
	blocksize = sqrt(n);
	for(int i =0 ; i < n; i++)cin>>a[i];
	int x,y;
	for(int i =0 ;i < t ; i++){
		cin>>x>>y;
		qu[i].L = x - 1;
		qu[i].R = y - 1;
		qu[i].ind = i;
	}
	sort(qu,qu+t,mo_cmp);
	int mo_l=0,mo_r=-1,l,r;

	for(int i= 0;i < t; i++){
		l = qu[i].L;
		r = qu[i].R;
		while(mo_r < r){
			mo_r++;
			add(a[mo_r]);
		}
		while(mo_r > r){
			rem(a[mo_r]);
			mo_r --;
		}
		while(mo_l < l){
			rem(a[mo_l]);
			mo_l++;
		}
		while(mo_l > l){
			mo_l --;
			add(a[mo_l]);
			
		}
		ans[qu[i].ind] = cur ;
	}
	for(int i =0 ;i <t ;i++)cout<<ans[i]<<endl;
	return 0;
}
