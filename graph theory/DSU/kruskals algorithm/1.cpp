//kruskals algorithm

#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int parent[N];
int size[N];

multiset<int> sizes;

void make(int v){
    parent[v]=v;
    size[v]=1;
    sizes.insert(1);

}

int find(int v){
    if(v==parent[v])return v;
    //path compression
    
    return parent[v]=find(parent[v]);
}

void merge(int a,int b){

    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));

    sizes.insert(size[a]+size[b]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a==b)return;

    else{
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        merge(a,b);
        size[a]+=size[b];
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;

    for(int i=1;i<=n;i++)make(i);

    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());

    int sum=0;

    for(auto & edge : edges){
        int wt=edge.first;

        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v))continue;
        Union(u,v);
        sum+=wt;

    }

    cout<<sum<<"\n";
}