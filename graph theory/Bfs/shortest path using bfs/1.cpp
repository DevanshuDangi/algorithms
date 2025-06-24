//Shortest path using BFS
//when weight of every edge is same


#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<int> g[N];

bool vis[N];
int level[N];

void bfs(int source){

    queue<int> q;
    q.push(source);

    vis[source]=true;

    while(!q.empty()){
        int currver=q.front();
        q.pop();
        // cout<<currver<<" ";

        for(auto c : g[currver]){
            if(vis[c])continue;

            vis[c]=true;
            q.push(c);

            level[c]=level[currver]+1;

        }
    }
}


int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    //we have to find min distance between node1 and node 2;
    int v1,v2;cin>>v1>>v2;

    bfs(v1);

    cout<<level[v2]<<"\n";

}

/*

i/p

13 12
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
8 9



o/p

6
*/