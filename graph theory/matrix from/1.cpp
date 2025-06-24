//matrix form
//flood flkill problem
//https://leetcode.com/problems/flood-fill/description/

#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int initial_colour,int final_colour,vector<vector<int>> &image){
    int n=image.size();
    int m=image[0].size();

    if(i<0 || j<0 || i>=n || j>=m)return;

    if(image[i][j]!=initial_colour)return;
    image[i][j]=final_colour;

    dfs(i+1,j,initial_colour,final_colour,image);
    dfs(i-1,j,initial_colour,final_colour,image);
    dfs(i,j+1,initial_colour,final_colour,image);
    dfs(i,j-1,initial_colour,final_colour,image);
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> image(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>image[i][j];
        }
    }
    int sr,sc;cin>>sr>>sc;
    int initial_colour,final_colour;
    cin>>initial_colour>>final_colour;
    dfs(sc,sr,initial_colour,final_colour,image);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<image[i][j]<<" ";
        }cout<<"\n";
    }
}
