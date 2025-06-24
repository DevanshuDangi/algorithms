///DEPTH FIRST SEARCH

#include<bits/stdc++.h>
using namespace std;

int N=1e5+10;
vector<vector<int>> g(N);


//pseudo code for dfs
void dfs1(int vertex){

    //take action on vertex after entering the vertex

    for(auto child : g[vertex]){

        //take action on child before entering the child node

        dfs1(child);

        //take action on child after exiting the child node

    }

    //take action on vertex before exiting the vertex
}

vector<bool> vis(N,0);

void dfs(int vertex){//O(no of edges)

    if(vis[vertex])return;

    vis[vertex]=true;

    //
    cout<<vertex<<" \n";

    for(auto child : g[vertex]){

        if(vis[child]==false){
            cout<<"parent "<<vertex<<"    child "<<child<<"\n";
            dfs(child);
            }
    }

}

void dfs2(int vertex){//O(no of edges)

    if(vis[vertex])return;

    vis[vertex]=true;

    cout<<vertex<<" \n";

    for(auto child : g[vertex]){

        if(vis[child]==false){
            dfs2(child);
            }
    }

}


int main(){
    int n,m;cin>>n>>m;

    for(int i=0;i<m;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    dfs2(1);

    // for(int i=1;i<=9;i++){
    //     cout<<i<<"-->";
    //     for(auto x :g[i])cout<<x<<" ";cout<<"\n";
    // }
}

// //input 
// 9 8
// 1 2
// 1 3 
// 1 4
// 2 5
// 2 6
// 2 7
// 6 9
// 3 8


// //output


