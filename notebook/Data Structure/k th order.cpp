#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int cnt[maxN];

typedef tree<
  pair<int,int>,
  null_type,
  less<pair<int,int> >,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_tree;

int main() {
  int n;  cin>>n;
  ordered_tree tree;
  for(int i=1;i<=n;i++) {
    int x,trash;
    cin>>x>>trash;
    cnt[tree.order_of_key(make_pair(x,i))]++;
    tree.insert(make_pair(x,i));    
  }
  for(int i=0;i<=n-1;i++) cout<<cnt[i]<<"\n";
}