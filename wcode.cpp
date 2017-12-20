#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"here"<<endl;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int dp[1001][1001];
    for(int i=0;i<=n;i++)
    {
       for(int j=0;j<=m;j++)
       {
           cout<<"in1"<<endl;
           if(i==0||j==0)
           dp[i][j]=0;
           else 
           {
            cout<<"in2"<<endl;
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
    }

    cout<<n-dp[n][m];
}