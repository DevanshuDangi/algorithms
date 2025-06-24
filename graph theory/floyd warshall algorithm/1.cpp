//FLOYD WARSHALL ALGORITHM
//https://cses.fi/problemset/task/1672
//min dist of all pairs
//(V^3)

#include <bits/stdc++.h>
using namespace std;



const int GN=505;
// vector<pair<int ,int>> g[GN];
long long dist[GN][GN];


int main(){
  long long n,m,q;cin>>n>>m>>q;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dist[i][j]=1e16;
      if(i==j)dist[i][j]=0;
    }
  }



  for(int i=0;i<m;i++){
    long long v1,v2,len;cin>>v1>>v2>>len;
    dist[v1][v2]=dist[v2][v1]=min(len,min(dist[v1][v2],dist[v2][v1]));
  }

  // main algo begins here

  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(dist[i][k]==1e16 || dist[k][j]==1e16)continue;
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }

  //

  while(q--){
    int v1,v2;cin>>v1>>v2;
    if(dist[v1][v2]==1e16 )cout<<"-1\n";
    else cout<<dist[v1][v2]<<"\n";
  }
  return 0;
}


