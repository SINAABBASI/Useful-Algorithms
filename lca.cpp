#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define MAX 100011
#define LOGN 21
#define inf 2000000007
#define mod 1000000000
#define mp make_pair


/*-------------LCA_FELEXIBLE----------------*/
int deep[MAX],jump[MAX][LOGN],mi[MAX][LOGN];

void dfs0(int u, int prev, int dep , int len){
    deep[u] = dep;
    jump[u][0] = prev;
    mi[u][0] = len;
    for(int i = 1 ; i < LOGN ;i++){
        jump[u][i] = jump[ jump[u][i-1] ][i-1];
        mi[u][i] = min( mi[u][i-1] ,  mi[jump[u][i-1]][i-1]);
    }
    for(auto it = g[u].begin();it != g[u].end() ; ++it){
        int v = (*it).first ;
        int w = (*it).second ;
        if(deep[v] == -1){
            dfs0(v , u ,dep + 1, w);
        }
    }
}

int swam(int x , int y){
    for(int i = LOGN - 1 ; i >= 0; i--){
        
        if((1<<i) <= y ){
            y -= (1<<i);
            x = jump[x][i];
        }

    }
    return x;
}


int lca(int x,int y){
    if(deep[x] > deep[y]) x = swam(x , deep[x] - deep[y]);
    if(deep[y] > deep[x]) y = swam(y , deep[y] - deep[x]);
    if(x == y) return x;
    for(int i = LOGN  - 1; i >= 0 ; i--){

        if(jump[x][i] != jump[y][i]){
            x = jump[x][i];
            y = jump[y][i];
        }

    }
    return jump[x][0];
}

int query(int x , int len){
    int ans = inf;
    for(int i =LOGN - 1; i >= 0; i--){
        
        if((1<<i) <= len){
            len -= (1<<i);
            ans = min(ans, mi[x][i]);
            x = jump[x][i];
        }

    }
    return ans;
}

void pre_lca(){
    memset(deep,-1,sizeof deep);
    for(int i = 1; i <= n ; i++){
       if(deep[i] == -1) dfs0(i,0,0,0);
    }
}

/*------------------------------------------*/
