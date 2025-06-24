//Beadth first search

#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> g[N];

bool vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);

    vis[source]=true;

    while(!q.empty()){
        int currvertex=q.front();
        q.pop();

        cout<<currvertex<<" ";

        for(auto child : g[currvertex]){
            if(vis[child])continue;

            else q.push(child);
            vis[child]=true;

            level[child]=level[currvertex]+1;
        }
    }

    cout<<"\n";
}

int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(1);

    for(int i=1;i<=n;i++)cout<<i<<" : "<<level[i]<<"\n";
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
*/


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



/*
i/p

6 9
1 3
1 5
3 5
3 4
3 2
3 6
2 6
4 6
5 6

o/p

1 3 5 4 2 6
1 : 0
2 : 2
3 : 1
4 : 2
5 : 1
6 : 2
*/  