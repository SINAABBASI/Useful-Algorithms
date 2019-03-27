#include <bits/stdc++.h>

using namespace std;
#define MAX 100010

int pat[MAX],height[MAX];
vector< pair<int,pair<int,int>  > > e[MAX];

int getroot(int a){
    if(pat[a]==a)return a;
    pat[a]=getroot(pat[a]);
    return pat[a];
}

void update(int a,int b){
    int ra=getroot(a),rb=getroot(b);
    if( ra==rb )return;
    if( height[ra]>=height[rb]){
        pat[rb]=ra;
        if(height[ra]==height[rb]) height[ra]++;
    } 
    else
        pat[ra]=rb;
}


bool cmp (pair<int,pair<int,int>  > x, pair<int,pair<int,int> > y){
    return x.first < y.first;
}

void find_mst(){
    sort(e,e+m,cmp);
    for(int i=0; i<m; i++){
        int f=g[i].second.first;
        int t=g[i].second.second;
        if( query(f,t) == 0){
            MST.push_back(g[i].second);
            update(f,t);
        }
    }
    
}


int main() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 0; i  <m; i++){
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;

    }
    for(int i=0;i<=n;i++) pat[i]=i;
    memset(height,0,sizeof height);
    
    find_mst();

    return 0; 
}