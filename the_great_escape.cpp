#include<bits/stdc++.h>
using namespace std;
int start,n,m,found,dist[3510];
vector<int> adj[3510];
void bfs(int i)
{
    int checked[3510]={0};
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        if(!checked[temp])
        {
           checked[temp]=1;
           for(int j=0;j<adj[temp].size();j++)
           {
               dist[adj[temp][j]]=dist[adj[temp][j]]==0? dist[temp]+1:min(dist[adj[temp][j]],dist[temp]+1);
               q.push(adj[temp][j]);
           }
        }
    }
}

int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  cin>>start>>found;
  dist[start]=0;
  bfs(start);
  cout<<dist[found]<<endl;
}