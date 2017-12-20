#include <bits/stdc++.h>
using namespace std;
long long int dp[5010];
int sign(long long int a)
{
    return (a>0)?1:0;
}
int main()
{
std::ios::sync_with_stdio(false);
long long int n,M=0;
cin>>n;
vector<long long int> arr(n);

for(long long int i=0;i<n;i++)
{
   long long int temp,m=0;
   cin>>temp;
   arr[i]=temp;
   for(long long int j=0;j<i;j++)
    if(abs(arr[j])<abs(arr[i])&&arr[i]!=0&&arr[j]!=0&&sign(arr[i])!=sign(arr[j]))
    m=max(m,dp[j]+1);

    if(m==0)
    dp[i]=1;
    else
    dp[i]=m;
   M=max(M,dp[i]); // assignment line
}
cout<<M<<endl;
/*cout<<"displaying dp: "<<endl;
for(int i=0;i<n;i++)
cout<<dp[i]<<" ";*/
}