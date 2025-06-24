//cycle in a graph
//how to find a cycle in a given graph
//https://www.interviewbit.com/problems/cycle-in-undirected-graph/
//https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

//keep track of the traversal

#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;

vector<bool> vis(10000,false);

bool dfs(int ver,int par){

    vis[ver]=true;

    bool isloopexist=false;

    for(auto c : g[ver]){

        if(vis[c] && c==par)continue;

        if(vis[c])return true;

        isloopexist |=dfs(c,ver);

    }

    return isloopexist;
}


int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isloopexist=false;

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        else{
            if(dfs(i,0)){
                isloopexist=true;
                break;
            }
        }
    }

    if(isloopexist)cout<<"YES\n";
    else cout<<"NO\n";
}

