#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 20;
const int logn = 20; // log(10^5) at base 2 is 16.67
int n, q;
vector<int> G[maxn];
int dep[maxn];
int P[maxn][logn];

//We would be precomputing a 2D table P such that P[i][j] stores the 2^j th ancestor for node i. 

void dfs(int u,int f)
{
	dep[u] = dep[f] + 1;
	
	P[u][0] = f;
	for(int i = 1; i < logn; i++)
		P[u][i] = P[P[u][i - 1]][i - 1];

//If a node does not have a (2^(j-1))th ancestor
//Then it does not have a (2^j)th ancestor
//and hence P[i][j] should remain -1
//Else the (2^j)th ancestor of node i
//is the (2^(j-1))th ancestor of ((2^(j-1))th ancestor of node i)
		
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(v == f) continue;
		dfs(v, u);
	}
}
int getlca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u, v); // u should have greater depth
	for(int i = logn - 1; i >= 0; i--)
		if(dep[P[u][i]] >= dep[v]) u = P[u][i];
		// find the largest depth ancestor of 'u' which has depth greater than or equal to
		// 'v'
	if(u == v) return u; // if this is same as 'v' then we return this
	for(int i = logn - 1; i >= 0; i--)
		if(P[u][i] != P[v][i])
		{
			u = P[u][i];
			v = P[v][i];
		}
	return P[u][0];
}

int dist(int x,int y)
{
	return dep[x] + dep[y] - 2 * dep[getlca(x, y)];
}

int main()
{
	cin>>n>>q;

	for(int i = 2, p; i <= n; i++)
	{
		cin>>p;
		G[i].push_back(p);
		G[p].push_back(i);
	}

	dfs(1, 0);

	while(q--)
	{
		int a, b, c;
		cin>>a>>b>>c;
		int w = getlca(a, b) ^ getlca(a, c) ^ getlca(b, c);
		cout<<max(max(dist(w, a), dist(w, b)), dist(w, c)) + 1;
	}

	return 0;
}

/*
read the sparse table tutorial at "https://www.hackerrank.com/topics/lowest-common-ancestor"
problem link "http://codeforces.com/contest/832/problem/D"
*/