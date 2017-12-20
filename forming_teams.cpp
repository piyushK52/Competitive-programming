#include <bits/stdc++.h>
using namespace std;
int num = 0, visited[110];
vector<int> adj[110];

int dfs(int i, int size, int parent) 
{
  visited[i] = 1;
  for (int j = 0; j < adj[i].size(); j++)
    { if(visited[adj[i][j]]&&size%2!=0&&parent!=adj[i][j]) 
      return 1;
      if (adj[i][j] != parent && !visited[adj[i][j]])
      if(dfs(adj[i][j], ++size, i)==1)return 1;}
  
return 0;
}

int main() 
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) 
  {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
    if (!visited[i] && dfs(i,1,-1))
    num++;/*cout<<"odd cycle found starting from: "<<i<<endl;}*/
  
    if((n-num)%2!=0)
    num++;

    cout<<num<<endl;
}