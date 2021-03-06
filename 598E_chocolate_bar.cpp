#include <bits/stdc++.h>
using namespace std;

int dp[31][31][51];

int f(int x,int y,int k)
{
	if(dp[x][y][k]||x*y==k||!k) 
		return dp[x][y][k];
	
	int ret=1e9;
	
	for(int i=1;i<=x-i;++i)
		for(int j=0;j<=k;++j)
			ret=min(ret,y*y+f(i,y,k-j)+f(x-i,y,j));
	for(int i=1;i<=y-i;++i)
		for(int j=0;j<=k;++j)
			ret=min(ret,x*x+f(x,y-i,k-j)+f(x,i,j));
	return dp[x][y][k]=ret;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<f(a,b,c)<<endl;
	}
}