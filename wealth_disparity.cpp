#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int w[100001];
vector<int> adj[100001];
int ans = 0;
void dfs(int i, int mx)
{
  ans=max(ans,mx-w[i]);
  mx=max(mx,w[i]);
  for(int a=0;a<adj[i].size();a++)
  dfs(adj[i][a],mx);
}


int main() 
{
  int n, x, s;
  cin >> n;
  for (int i = 1; i <= n; i++) 
    cin >> w[i];
  
  for (int i = 1; i <= n; i++) 
  {
    cin >> x;
    if (x != -1) 
      adj[x].push_back(i);
    else
      s = i;
  }
  
  dfs(s,w[s]); // current node, previous maximum
  
  cout << ans << endl;
}