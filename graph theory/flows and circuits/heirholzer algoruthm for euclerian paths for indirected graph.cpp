#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> path;
vector<bool> seen;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    while (!g[node].empty()) {
        auto [son, idx] = g[node].back();
        g[node].pop_back();
        if (seen[idx]) { continue; }
        seen[idx] = true;
        dfs(son);
    }
    path.push_back(node);
}

int main() {
    cin >> n >> m;

    vector<int> degree(n, 0);
    g.resize(n);
    seen.resize(m, false);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
        degree[x]++;
        degree[y]++;
    }

    // Check for Eulerian path or circuit conditions
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) {
            odd_count++;
        }
        if (degree[i] > 0) {
            if (!visited[i]) {
                dfs(i);  // Start DFS from any non-zero degree vertex
            }
        }
    }

    if (odd_count != 0 && odd_count != 2) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // Check if all vertices with edges were visited
    for (int i = 0; i < n; i++) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    reverse(path.begin(), path.end());

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto node : path) { cout << node + 1 << ' '; }
    }

    return 0;
}
