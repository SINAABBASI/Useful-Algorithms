#include <bits/stdc++.h>
#define MAX 1000011
#define LOG 21
#define mod 4432676798593
using namespace std;

vector<int> g[MAX];
int n;

int DP[LOG][MAX],level[MAX];
void _dfs(int u){
    for(auto v : g[u]){
        if(DP[0][u] != v){
            DP[0][v] = u;
            level[v] = level[u] + 1;
            _dfs(v);
        }
    }
}
void preprocess(){
    ////One Base Graph
    level[1] = 0;
    DP[0][1] = 0;
    _dfs(1);
    for(int i = 1 ; i < LOG ; i++)
        for(int j = 1; j <= n; j++)
            DP[i][j] = DP[i-1][DP[i-1][j]];
}

int lca(int a,int b){
    ///b is greater
    if(level[a] > level[b])swap(a,b);
    int d = level[b] - level[a];
    for(int i = 0; i < LOG ;i ++){
        if(d & (1<<i))
            b = DP[i][b];
    }
    if(a==b)return a;
    for(int i= LOG - 1 ; i >=0 ; i--){
        if(DP[i][a] != DP[i][b]){
            a = DP[i][a];
            b = DP[i][b];
        }
    }
    return DP[0][a];
}

int dist(int a,int b){
    return level[a] + level[b] - 2*level[lca(a,b)];
}





