#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
char ar[55][55];
ll visited[55][55];

void dfs(ll i,ll j,ll ip,ll jp)
{
	if(ar[i][j] !=ar[ip][jp])
	return;
	if(visited[i][j]==1)
	{
		cout<<"Yes";
		exit(0);
	}
	visited[i][j]=1;
	if(i+1<=n && i+1!=ip)
	dfs(i+1,j,i,j);
	if(j+1<=m && j+1!=jp)
	dfs(i,j+1,i,j);
	if(i-1>=1 && i-1!=ip)
	dfs(i-1,j,i,j);
	if(j-1>=1 && j-1!=jp)
	dfs(i,j-1,i,j);
	
}
int main()
{
	cin>>n>>m;
	ll i,j;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		  cin>>ar[i][j];
		
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		{
			memset(visited,0,sizeof(visited));
			dfs(i,j,i,j);
		}
	
	cout<<"No"<<endl;
	return 0;
}