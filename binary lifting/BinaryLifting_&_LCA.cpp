#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;   // max number of nodes
const int LOG = 20;    // ~ log2(N)

vector<int> g[N];
int up[N][LOG];   // up[v][j] = 2^j-th ancestor of v
int depth[N];

// Preprocessing DFS
void dfs(int v, int p) {
    up[v][0] = p;   // immediate parent
    for (int j = 1; j < LOG; j++) {
        if (up[v][j-1] != -1)
            up[v][j] = up[up[v][j-1]][j-1];
        else
            up[v][j] = -1;
    }
    for (int to : g[v]) {
        if (to == p) continue;
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
}

// K-th ancestor of a node
int getKthAncestor(int v, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            v = up[v][j];
            if (v == -1) break;
        }
    }
    return v;
}

// LCA using Binary Lifting
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    // Lift a up to same depth as b
    int diff = depth[a] - depth[b];
    a = getKthAncestor(a, diff);

    if (a == b) return a;

    // Jump both up until their parents match
    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0]; // parent of both
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;  // number of nodes
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(up, -1, sizeof(up));
    depth[1] = 0;
    dfs(1, -1);  // root at 1

    int q; cin >> q;  // number of queries
    while (q--) {
        int type; cin >> type;
        if (type == 1) { // kth ancestor query
            int node, k; cin >> node >> k;
            cout << getKthAncestor(node, k) << "\n";
        } else if (type == 2) { // lca query
            int a, b; cin >> a >> b;
            cout << lca(a, b) << "\n";
        }
    }

    return 0;
}
