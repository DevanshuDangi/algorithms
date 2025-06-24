//LCA in a generic tree

#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;
vector<int> parent(10000,-1);

void dfs(int v,int p){

    for(auto c : g[v]){

        if(c==p)continue;

        parent[c]=v;

        dfs(c,v);
    }
}

vector<int> Path(int v){
    vector<int> path;

    while(v!=-1){
        path.push_back(v);
        v=parent[v];
    }

    reverse(path.begin(),path.end());

    return path;
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }


    dfs(1,0);

    int v1,v2;cin>>v1>>v2;
    vector<int> path1,path2;
    path1=Path(v1);
    path2=Path(v2);

    // for(auto x : path1)cout<<x<<" ";cout<<"\n";
    // for(auto x : path2)cout<<x<<" ";cout<<"\n";
    int lca=1;
    for(int i=0;i<min(path1.size(),path2.size());i++){
        if(path1[i]==path2[i])lca=path1[i];
        else break;
    }
    cout<<lca<<"\n";
}


/*
i/p

13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
6 12

*/

/*
o/p is 5
*/