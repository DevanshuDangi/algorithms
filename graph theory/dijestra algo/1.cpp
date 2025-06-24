//dijestra algorithm for weighted graph
//min dist from 1 source to all nodes
//O((V+E)*logV)

//not for negative edge weight will give wrong output

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2; 
vector<pair<int,int>> g[N];

bool vis[N];
vector<int> dist(N,INT_MAX);

void bfsdijestra(int source){

    set<pair<int,int>> s;
    //dist,node

    s.insert({0,source});
    dist[source]=0;

    
    while(s.size()>0){
        auto it=*s.begin();
        int distv=it.first;
        int curr=it.second;


        s.erase(it);
        if(vis[curr])continue;
        vis[curr]=1;

        for(auto c : g[curr]){

            int child=c.first;
            int wt=c.second;

            // if(newdist<old_dist)
            if(dist[curr]+wt < dist[child]){
                dist[child]=dist[curr]+wt;
                s.insert({dist[child],child});
            }
        }
    }
}

int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2,wt;cin>>v1>>v2>>wt;
        g[v1].push_back({v2,wt});
    }
    
    bfsdijestra(1);

    for(int i=1;i<=6;i++){
        cout<<i<<" "<<dist[i]<<"\n";
    }

}

/*
i/p

6 9
1 2 1
1 3 5
2 3 2
2 5 1
2 4 2
3 5 2
4 5 3
4 6 1
5 6 2

o/p
 
1 0
2 1
3 3
4 3
5 2
6 4
*/