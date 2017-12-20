#include <bits/stdc++.h>
using namespace std;
vector<int> g[200179];
int n,x,y,i,a[200179];
set<int> s[200179]; // all possible gcds obtainable for a vertex 'i'

void dfs(int v,int p,int gcd_now)
{
    for(auto w:s[p])
    s[v].insert(__gcd(w,a[v]));
    s[v].insert(gcd_now);
    s[v].insert(__gcd(gcd_now,a[v]));
    b=__gcd(gcd_now,a[v]);
    for(auto w:g[v])
      if(w!=p)
      dfs(w,v,gcd_now);
}

int main()
{
    for(cin>>n,i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<n;i++)
    cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1,0,0);
    for(i=1;i<=n;i++)
    cout<<*s[i].rbegin()<<" ";
}