#include<bits/stdc++.h>
using namespace std;
vector<int> adj[205];
bool vis[205];

void dfs(int v)
{
	vis[v]=true;
	for(int i=0;i<adj[v].size();i++)
	{
		int to=adj[v][i];
		if(!vis[to])
		{
			dfs(to);
		}
	}
}

int main()
{
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
        int x,y;
        cin>>x;
		while(x--)
		{
			cin>>y;
			adj[i].push_back(n+y);
			adj[n+y].push_back(i);
		}
	}
	int count=0,count2=0;
    
    for(i=1;i<=n;i++)
	{
		if(!vis[i] && adj[i].size()!=0)
		{
			count++;
			dfs(i);
		}
		else if(adj[i].size()==0)
		{
			count2++;
			count++;
			dfs(i);
		}
	}
	if(count2!=n)
	cout<<count-1<<endl;
	else
	cout<<count2<<endl;
}