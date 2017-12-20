#include<bits/stdc++.h>
using namespace std;
int p[30010]={0},n,k,dp[30010][600],last;

int solve(int i,int K)
{
   //cout<<"***"<<i<<endl;
   //int d=K-(k-270);
   if(i>last||K+(k-270)<=0)
   return 0;
   if(dp[i][K]!=-1)
   return dp[i][K];
   //cout<<"calling: "<<i+K-1<<" "<<i+K<<" "<<i+K+1<<" K is:"<<K<<endl;
   dp[i][K]=p[i]+max(solve(i+K+(k-270)-1,K-1),max(solve(i+K+(k-270),K),solve(i+K+(k-270)+1,K+1)));
   
   return dp[i][K];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        last=t;
        p[t]++;
    }
    
    cout<<solve(k,k-(k-270))<<endl;

    //for(int i=0;i<=last;i++)
    //cout<<i<<": "<<dp[i]<<endl;
}