#include<bits/stdc++.h>
using namespace std;

long long zz = 1e9 + 7;
 
long long modadd(long long a, long long b){
    return ((a % zz) + (b % zz)) % zz;
}
  

int n,m;
int func(int s,int mask,vector<vector<int>> &g,vector<vector<int>> &dp){
    if((mask>>s)&1)return 0;
    else mask|=(1<<s);

    bitset<5> a(mask);

    if(dp[s][mask]!=-1)return dp[s][mask];

    // cout<<s<<" "<<a<<"\n";
    
    if(s==n-1){
        if(mask==(1<<n)-1)return 1;
        else return 0;
    }

    int ans=0;
    for(auto ch : g[s]){
        // ans+=func(ch,mask,g,dp);
        ans=modadd(ans,func(ch,mask,g,dp));
    }
    return dp[s][mask]=ans;
}


void solve(){
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
    }
    vector<vector<int>> dp(n,vector<int> (1<<n,-1));
    cout<<func(0,0,g,dp)<<"\n";
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.in", "w", stderr);
#endif
  // makeisprime();
  // fillprimefactors();
  // EulerTotientFunction();
  int T = 1;
  // cin >> T;
  while(T--) {
    solve();
  }
 
  return 0;
}