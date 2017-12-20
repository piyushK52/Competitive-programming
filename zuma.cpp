#include<bits/stdc++.h>
using namespace std;
int n,dp[501][501],a[501];
int dp(int i,int j)
{
 if(~dp[i][j])
 return dp[i][j];
 dp[i][j]=INT_MAX;
 for(int k=i;k<=j;++k)
   if(a[k]==a[i])
    dp[i][j]=min(dp[i][j],(k>i+1?dp(i+1,k-1):1)+(k<j?dp(k+1,j):0));
 return dp[i][j];
}
int main()
{
 memset(mem,-1,sizeof mem);
 scanf("%d",&n);
 for(int i=0;i<n;++i)
 scanf("%d",a+i);
 printf("%d\n",dp(0,n-1));
}