#include<bits/stdc++.h>
using namespace std;
#define inf -1e9-7;
int dp[1010][1010],m=0;
string s;
int solve(int i, int j)
{
  //cout<<"inside the recursion "<<i<<" "<<j<<endl;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(i>j)
  {dp[i][j]=0;return 0;}
  if(i==j)
  {dp[i][j]=1;return 1;}
  if(s[i]==s[j])
  {
   int t=solve(i+1,j-1); m=max(m,t+2); dp[i][j]=t+2;return t+2; 
  }
  else
  {
    solve(i+1,j),solve(i,j-1),solve(i+1,j-1);dp[i][j]=inf;return inf;
  }
}
void display(int i,int j)
{
  while(i<=j)
  {
    cout<<s[i];i++,j--;
  }
}

int main()
{
  memset(dp,-1,sizeof(dp));
  cin>>s;
  solve(0,s.size()-1);
  cout<<m<<endl;

  cout<<"displaying the substring: "<<endl;
  for(int i=0;i<=s.size()-1;i++)
    for(int j=i;j<=s.size()-1;j++)
     if(dp[i][j]==m)
     {
       display(i,j);
     }
}