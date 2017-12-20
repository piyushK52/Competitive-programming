#include<bits/stdc++.h>
using namespace std;
int dp[2][410][410];
int solve(int i,int* t,int n,int k,bool state)
{
  if(n==i||k==0)
  return 0;
  
  if(dp[state][i][k]!=-1)
  return dp[state][i][k];
  
  if(state==0) // if he currently does not owns a buffalo
  dp[state][i][k]=max(-t[i]+solve(i+1,t,n,k-1,!state),solve(i+1,t,n,k,state)); // he can either buy it or not
  else
  dp[state][i][k]=max(t[i]+solve(i+1,t,n,k-1,!state),solve(i+1,t,n,k,state)); // if owns one he can either sell it or not
  
  return dp[state][i][k];
}

int main()
{
    int n,k;
    cin>>n>>k;

    int t[n];
    for(int i=0;i<n;i++)
    cin>>t[i];
    memset(dp,-1,sizeof(dp));
    k-=(k%2);

    cout<<max(0,solve(0,t,n,k,0));
}