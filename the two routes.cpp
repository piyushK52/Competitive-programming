#include <bits/stdc++.h>
using namespace std;
int n,m,arr[405][405],u,v,vis[405],dep[405];

int bfs(int f)
{
    memset(vis,-1,sizeof vis);
    queue<int> q;
    q.push(1); 
    dep[1]=0;
    vis[1] = 0;
    int dep=0,sz=1,cur=1;
    while(!q.empty())
    {
        cur=q.front(),q.pop();
        for(int i=1;i<=n;i++)
        if(vis[i]==-1 && arr[cur][i]==f)
        {
            q.push(i), vis[i]=vis[cur]+1;
            if(i==n)
            return vis[i];
        }
    }
    
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        arr[u][v]=arr[v][u]=1;
    }
    int bus=bfs(0),train=bfs(1);
    cout<<(bus&&train?max(bus,train):-1)<<endl;
}