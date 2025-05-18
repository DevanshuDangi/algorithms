#include <bits/stdc++.h>
using namespace std;
 
static const int MAXN = 200000;
static const int LOG  = 18; // 2^18 = 262144 > 2e5
 
int up[MAXN+1][LOG+1];
int depth_arr[MAXN+1];
 
int lift_node(int u, int k) {
    // lift u up by k steps (or to 0 if it goes above the root)
    for(int j = 0; j <= LOG && u; ++j){
        if(k & (1 << j))
            u = up[u][j];
    }
    return u;
}
 
// LCA #1: binary‐search style (find largest common prefix of depth)
int LCABS(int u, int v){
    if(depth_arr[u] < depth_arr[v])
        swap(u, v);
    // Lift u to same depth as v
    u = lift_node(u, depth_arr[u] - depth_arr[v]);
 
    // Now binary‐search on [0 .. depth_arr[u]] for the split point
    int lo = 0, hi = depth_arr[u];
    while(lo < hi){
        int mid = (lo + hi) >> 1;
        int x1  = lift_node(u, mid);
        int x2  = lift_node(v, mid);
        if(x1 == x2)
            hi = mid;
        else
            lo = mid + 1;
    }
    // After this, lo = minimal steps to reach LCA, so:
    return lift_node(u, lo);
}
 
 
int lca(int u, int v) {
    if(depth_arr[u] < depth_arr[v])
        swap(u, v);
    // 1) lift u up to the same depth as v
    u = lift_node(u, depth_arr[u] - depth_arr[v]);
    if(u == v) 
        return u;
    // 2) lift both u and v up until their parents diverge
    for(int j = LOG; j >= 0; --j){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    // now up[u][0] (== up[v][0]) is the LCA
    return up[u][0];
}
 
int main(){
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
    int n, q;
    cin >> n >> q;
 
    // Read parents e[2..n]
    // We'll treat 1 as the root, with parent 0
    depth_arr[1] = 0;
    up[1][0] = 0;
    for(int j = 1; j <= LOG; ++j)
        up[1][j] = 0;
 
    for(int i = 2; i <= n; ++i){
        int p;
        cin >> p;
        up[i][0] = p;
        depth_arr[i] = depth_arr[p] + 1;
        // initialize the rest of up[i][*] to 0 for now
        for(int j = 1; j <= LOG; ++j)
            up[i][j] = 0;
    }
 
    // Build full binary‐lifting table
    for(int j = 1; j <= LOG; ++j){
        for(int i = 1; i <= n; ++i){
            int mid = up[i][j-1];
            up[i][j] = mid ? up[mid][j-1] : 0;
        }
    }
 
    // Process queries
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}