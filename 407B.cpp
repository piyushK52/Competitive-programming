#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int dp[1010]={0},p[1010],sum[1010]={0};

int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   cin>>p[i];
   sum[0]=0;
   sum[1]=dp[1]=2;
   for(int i=2;i<=n;i++)
   {
       dp[i]+=((sum[i-1]-sum[p[i]-1])%MOD+2+MOD)%MOD; // 1 for going to p[i] and 1 for going forward
       sum[i]+=(dp[i]+sum[i-1])%MOD;
   }
   cout<<sum[n]<<endl;
}
