//subtree problems
//precomputation problem in subtree

/**

given Q queries ,Q<=1e5
in each query given V,
print subtree sum of V and no of even nodes in subtree in V

**/

#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;

int N=1e5;
vector<int> subtreesum(N,0),subtreeevennum(N,0);
//from both subtreesum and  subtreeevennum we have to do operations while goinf bottom to top

void dfs(int v,int p){
    subtreesum[v]=v;
    if(v%2==0)subtreeevennum[v]++;
    for(auto c : g[v]){
        if(c==p)continue;

        dfs(c,v);

        subtreesum[v]+=subtreesum[c];
        subtreeevennum[v]+=subtreeevennum[c];
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<i<<"  "<<subtreesum[i]<<"  "<<subtreeevennum[i]<<"\n";
    }

    // int q;cin>>q;
    // while(q--){
    //     int v;cin>>v;
    //     cout<<v<<"  "<<subtreesum[v]<<"  "<<subtreeevennum[v]<<"\n";

    // }
}

/*
                     1
    +----------------+---------+
    |                |         |
    2                3         13
    |                |
    5                4
   /|\              / \
  6 7 8            9   10
       \                \
         12              11
*/