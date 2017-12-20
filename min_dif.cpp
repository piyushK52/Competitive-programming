#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,sum=0;
bool dp[100][500];
int mdif()
{
   for(int i=0;i<=a.size();i++)
   dp[i][0]=true;
   for(int j=1;j<=sum;j++)
   dp[0][j]=false;
   
   for(int i=1;i<=a.size();i++)
   {
	   for(int j=1;j<=sum;j++)
	   {
		   dp[i][j]=dp[i-1][j];
		   if(a[i-1]<=j)
		   dp[i][j]|=dp[i-1][j-a[i-1]];
	   }
   }

   int dif=0;
   for(int j=sum/2;j>=0;j--)
   if(dp[a.size()][j]==true)
   {dif=sum-2*j;break;}

   return dif;
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
	  int t;cin>>t;sum+=t;
	  a.push_back(t);
  }

  cout<<"minimum difference is: "<<mdif();
}