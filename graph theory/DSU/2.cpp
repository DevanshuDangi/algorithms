//DSU question
//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbjVKMkhWTVBPXzlPQjFBdnlueHAyeHNPSVpBQXxBQ3Jtc0traVo1UWhScEZYQXQ4S0NoRm0zSW9ocnkxZ09KRXRtU1NGcnZETk1sWGtJVG1pWXZSTVJsS244VGFZOHI2XzJfdTQzV01pMUpZVzZiTjNKVDFTc09BVTJEdUM0V3R4VGh3X1BZS1pfVjVHVHVMS0pTYw&q=https%3A%2F%2Fwww.hackerearth.com%2Fchallenges%2Fcompetitive%2Fcode-monk-disjoint-set-union%2Fproblems%2F&v=L8SuKrpNc2Q

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
        make(i);
    }


    while(k--){
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