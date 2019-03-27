/*************O(V * E) ************/
//// res = vertex cover in biparted graph  and  a(g) + res = N


bool seen[MAX];
int matchR[MAX];
bool g[MAX][MAX];///would be Adj list

bool bpm(int u){
    for (int v = 0; v < MAX; v++){
        if (g[u][v] && !seen[v]){
            seen[v] = true; 
            if (matchR[v] < 0 || bpm(matchR[v])){
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(){ 
    memset(matchR, -1, sizeof(matchR));
    int result = 0; 
    for (int u = 0; u < MAX; u++){      
        memset(seen, 0, sizeof seen);
        if (bpm(u))
        result++;
    }
    return result;
}
