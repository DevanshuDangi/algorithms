//tree trversal
// dfs in a tree
//depth and height of a tree;

//for height we have to perform actoin while going bottom to top and for up we have to use perform action while top to bottom


#include<bits/stdc++.h>
using namespace std;

int N=1e5;

map<int,vector<int>> g;
vector<int> height(N,0),depth(N,0);

void dfs(int v,int p){
//in tree we can replace vis array by parent as there is not circular loop in tree
    
    for(auto c : g[v]){

        if(c==p)continue;

        depth[c]=depth[v]+1;

        dfs(c,v);

        height[v]=max(height[v],height[c]+1);
    }

}

int main(){
    int n;cin>>n;

    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<height[i]<<" "<<depth[i]<<"\n";
    }
}

/*
input
11
1 2
1 3
1 13
3 4
4 10
2 5
5 6
5 7
5 8
8 12
*/

/*
         1
    +----+----+
    |    |    |
    2    3    13
    |    |
    5    4
   /|\    \
  6 7 8    10
         \
         12
*/
