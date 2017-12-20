#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
int d[2]={0};

void dfs(int n,int p,int dd)
{
   d[dd]++;
   for(int i=0;i<g[n].size();i++)
   {
	   if(g[n][i]==p)
	   continue;
	   dfs(g[n][i],n,dd^1);
   }
}
int main()
{
   int e;
   cin>>e;
   for(int i=0;i<e;i++)
   {
	   int a,b;
	   cin>>a>>b;
	   g[a].push_back(b);
	   g[b].push_back(a);
   }
   
   dfs(0,-1,0);
   cout<<d[0];
}