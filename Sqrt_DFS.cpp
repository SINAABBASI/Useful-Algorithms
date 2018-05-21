
#include <bits/stdc++.h>

using namespace std;
#define MAX 222
#define inf 2000000007
#define bsize 333
#define LOGN 21


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
        return
;    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0; 
}

