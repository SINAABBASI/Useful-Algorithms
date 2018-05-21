
#include <bits/stdc++.h>

using namespace std;
#define MAX 1000010
#define inf 2000000007
#define bsize 333
#define LOGN 21
vector<int> g[MAX];
int par[MAX],t[MAX],n,q;
/////lca
int deep[MAX],jump[MAX][LOGN];

void dfs0(int u , int pre , int dep){
    deep[u] = dep;
    jump[u][0] = pre;
    for(int i = 1 ; i < LOGN ; i++){
        jump[u][i] = jump[ jump[u][i-1] ][ i-1 ];
    }
    for(int i =  0;i < g[u].size() ;i++ ){
        if( deep[g[u][i]] == -1 ){
            t[g[u][i]] = u;
            dfs0(g[u][i],u,dep + 1);
        }
    }
}

int swam(int x ,int y){
    for(int i = LOGN - 1; i >= 0 ; i--){
        if((1<<i) <= y){
            y -= (1<<i);
            x = jump[x][i]; 
        }
    }
    return x;
}

int lca(int x,int y){
    if(deep[x] > deep[y]) x = swam(x,deep[x] - deep[y]);
    if(deep[y] > deep[x]) y = swam(y,deep[y] - deep[x]);
    if(x == y)return x;
    for(int i = LOGN - 1; i >= 0 ; i--){
        if(jump[x][i] != jump[y][i]){
            x = jump[x][i];
            y = jump[y][i];
        }
    }
    return jump[x][0];
}

void pre_lca(){
    memset(deep,-1,sizeof deep);
    for(int i = 1; i<= n ; i++)t[i] = i;
    dfs0(1,0,0);
}

/////
void dfs(int a, int pre){

    if(deep[a] < bsize){
        par[a] = 1;
    }
    else if(deep[a] % bsize  == 0)
        par[a] = t[a];
    else
        par[a] = par[t[a]];
    for(int i = 0 ; i < g[a].size() ; i++){
        if(g[a][i] != pre)dfs(g[a][i],a);
    }

}   
int ans ;

void solve(int u,int d){
    if(d < 2 * bsize){
        while(d--){
            u = t[u];
        }
        ans = u;
        return;
    }
    else{
        while(d > bsize){
            d -= ((deep[u] % bsize) + 1);
            u = par[u];
        }
        while(d > 0){
            u =t[u];
            d--;
        }
        ans = u;
        return;
        }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int a,b;
    for(int i =0 ;i < n - 1 ; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ///ofline part
    pre_lca();
    dfs(1,0);
    cin>>q;
    while(q--){
        cin>>a>>b;
        int k = lca(a,b);
        if(abs(deep[a] - deep[b]) < 2)
            cout<<k<<endl;
        else{
            if(deep[a] > deep[b]){
                int d = (deep[a] + deep[b]  + 1)/2;
                solve(a,d);
            }
            else{
                int d = (deep[b] + deep[a]  + 1)/2;
                solve(b,d);
            }
            cout<<ans<<endl;
        }
    }
    return 0; 
}

