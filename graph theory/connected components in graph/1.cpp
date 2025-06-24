// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
//how to find connnected components in a graph

#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;

vector<bool> vis(100000,0);

void dfs(int n){
    if(vis[n])return;
    vis[n]=true;    
    for(auto c : g[n]){
        if(vis[c]==false)dfs(c);
    }
}


int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        else{
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<"\n";
}


