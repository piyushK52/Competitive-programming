#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,mod=1e9+7;
long long dp[5005],sum[5005];
int main()
{
    cin>>n>>a>>b>>k;
    for(int i=1;i<=n;i++)
        dp[i]=1;

    while(k--)
    {
        for(int i=1;i<=n;i++)
            sum[i]=(sum[i-1]+dp[i])%mod;
        for(int i=1;i<=n;i++)
        {
            int l=max(1,i-(abs(b-i)-1));
            int r=min(n,i+(abs(b-i)-1));
            dp[i]=sum[r]-sum[l-1]-dp[i]+mod;
        }
    }
    cout<<(((dp[a]%mod)+mod)%mod)<<endl;
}