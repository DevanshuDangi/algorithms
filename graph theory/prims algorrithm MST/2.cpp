#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<pair<int,int>> g[]){

	set<pair<int,int>> s;
	// {wt, node}

	vector<int> vis(V, 0);

	s.insert({0,0});
	int sum = 0;
	while (!s.empty()) {
		// auto it = pq.top();
		auto it=*s.begin();
		// pq.pop();
		s.erase(s.find(it));
		int node = it.second;
		int wt = it.first;

		if (vis[node] == 1) continue;
		// add it to the mst
		vis[node] = 1;
		sum += wt;
		for (auto it : g[node]) {
			int adjNode = it.first;
			int edW = it.second;
			if (!vis[adjNode]) {
				// pq.push({edW, adjNode});
				s.insert({edW,adjNode});
			}
		}
	}
	return sum;
}


int main() {

	// int V = 5;
	// vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	// vector<vector<int>> adj[V];
	// for (auto it : edges) {
	// 	vector<int> tmp(2);
	// 	tmp[0] = it[1];
	// 	tmp[1] = it[2];
	// 	adj[it[0]].push_back(tmp);

	// 	tmp[0] = it[0];
	// 	tmp[1] = it[2];
	// 	adj[it[1]].push_back(tmp);
	// }


	int v;cin>>v;
	int e;cin>>e;

	vector<pair<int,int>> g[v];
	for(int i=0;i<e;i++){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;

		g[v1].push_back({v2,wt});
		g[v2].push_back({v1,wt});//remove this line if directed graph

	}



	int sum =spanningTree(v, g);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}


//i/p
// 5
// 6
// 0 1 2
// 0 2 1
// 1 2 1
// 2 4 2
// 2 3 2
// 3 4 1

// o/p is 5