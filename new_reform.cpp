#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,p,i,checked[100005];
vector<int> v[100005];

dfs(int x)
{
	a++;b+=v[x].size();checked[x]++;
	int j=0;
    while(j<v[x].size())
    {
		if(checked[v[x][j]]==0)dfs(v[x][j]);
		j++;
	}
}

main()
{
	cin>>n>>k;
	while(i<k)
    {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
    }
    i=1;
	while(i<=n)
    {
		a=0;b=0;
        if(checked[i]==0)
        dfs(i);
        if(b/2==a-1) // no. of edges will be atleast n-1, if they are not than there is a cycle and no isolated city is present
        p++;
		i++;
	}
	cout<<p;
}