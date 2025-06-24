//matrix method of graph representation
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int graph[n+1][n+1];
    //n<=1e3 or 1e4
    for(int i=0;i<m;i++){
        // int v1,v2;
        // cin>>v1>>v2;
        // graph[v1][v2]=1;
        // graph[v2][v1]=1;
        // //here we are making both v1,v2 and v2,v1 as 1 as it is bidirectional graph

        int v1,v2;
        cin>>v1>>v2;
        int wt;cin>>wt;

        graph[v1][v2]=wt;
        graph[v2][v1]=wt;
    }
}

// i/p
        // 6 9
        // 1 3 4
        // 1 5 3
        // 3 5 2
        // 3 4 7
        // 3 6 8
        // 3 2 9
        // 2 6 1
        // 4 6 2
        // 5 6 3
