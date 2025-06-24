//DSU
//O(alpha(n)) - alpha()reverseaskterman function
//alpha(n)<4 generally over a number of operations
 
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;

}

int find(int v){
    if(v==parent[v])return v;
    //path compression
    
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a==b)return;

    else{
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;

    }
}

int main(){
    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        Union(u,v);
    }

    int cnt=0;//no of connected components

    for(int i=1;i<=n;i++){
        if(find(i)==i){
            cnt++;
        }
    }

    cout<<cnt<<"\n";

}