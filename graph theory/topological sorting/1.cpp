#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef map<int, int> mi;
typedef map<long long int, long long int> mll;
typedef unordered_map<int, int> umi;
typedef unordered_map<long long int, long long int> umll;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<long long int> sll;
typedef multiset<long long> msll;
typedef unordered_set<int> usi;
typedef unordered_set<long long int> usll;
typedef stack<int> sti;
typedef stack<long long> stll;

struct CompareGreater {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};
typedef std::map<int, int, CompareGreater> decmap;

#define pb push_back
#define popb pop_back
#define ai(a,n) for(int j=0;j<n;j++)cin>>a[j];
#define ao(a,n) for(int j=0;j<n;j++)cout<<a[j]<<" ";
#define f(n) for(int i=0;i<n;i++)
#define printvec(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define printmap(m) for(auto x : m)cout<<x.first<<" "<<x.second<<"\n";


/////////////////////--C O D E-----S T A R T S -----H E R E--///////////////////////////////////
#include <bits/stdc++.h>

using namespace std;

void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
  vis[node] = 1;

  for (auto it: adj[node]) {
    if (!vis[it]) {
      findTopoSort(it, vis, st, adj);
    }
  }
  st.push(node);
}


vector < int > topoSort(int N, vector < int > adj[]) {
  stack < int > st;
  vector < int > vis(N, 0);
  for (int i = 0; i < N; i++) {
    if (vis[i] == 0) {
      findTopoSort(i, vis, st, adj);
    }
  }
  vector < int > topo;
  while (!st.empty()) {
    topo.push_back(st.top());
    st.pop();
  }
  return topo;

}

// { Driver Code Starts.
int main() {

  int N = 6;

  vector < int > adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  vector < int > res = topoSort(6, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 
