#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define MAX 1000100
#define inf 9000000000000000007
#define mod 1000000007
#define shift 1000000000

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll , null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set rem,st;

struct P
{
	ll l,r,id;
}a[MAX];
ll  ans[MAX] ={0};

bool cmp(P x , P y){
	return x.l <  y.l;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,l,r;
	cin>>n;
	for(int i = 0; i < n ;i++){
		cin>>l>>r;
		a[i].l = l + shift;
		a[i].r = r + shift;
		a[i].id = i;
	}
	sort(a,a+n,cmp);
	for(int i = 0; i < n ; i++ )st.insert(a[i].r);
	for(int i =0 ; i < n ;i++){
		ans[a[i].id] += ((int)st.order_of_key(a[i].r));
		ans[a[i].id] -= ((int)rem.order_of_key(a[i].r));
		rem.insert(a[i].r);
	}
	for(int i =0 ; i  < n ;i++)cout<<ans[i]<<endl;
 	return 0;
}
