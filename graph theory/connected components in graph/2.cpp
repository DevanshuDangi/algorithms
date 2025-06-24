//to also store connected component

#include<bits/stdc++.h>
using namespace std;

map <int,vector<int>> g;

vector<vector<int>> cc;

vector<bool> vis(100000,false);

void dfs(int n,vector<int> &currcc){
    if(vis[n])return;

    vis[n]=true;
    currcc.push_back(n);

    for(auto x : g[n]){
        dfs(x,currcc);
    }
}

int main(){
    int n,e;cin>>n>>e;
    
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for(auto v : g){
        vector<int> currcc;

        if(vis[v.first])continue;
        else{
            dfs(v.first,currcc);
            cc.push_back(currcc);
        }
    }


    for(auto  v : cc){
        for(auto x : v)cout<<x<<" ";
        cout<<"\n";
    }

}
