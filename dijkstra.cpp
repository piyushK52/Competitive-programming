#include <bits/stdc++.h>
using namespace std;

int dist[10001][10001];
bool done[10001];

void dijkstra(int dist[10001][10001], vector<pair<int,int> > *graph, int x)
{
    bool vis[10010];
    memset(vis,0,sizeof(vis));
    done[x]=1;
    dist[x][x]=0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q; // smallest first
    q.push(make_pair(0,x));

    while(!q.empty())
    {
        int v=q.top().second;
        q.pop();
        if(vis[v])
        continue;
        vis[v]=1;

        for(auto n: graph[v])
        {
            if(dist[x][n.second]>dist[x][v]+n.first)
            {
                dist[x][n.second]=dist[x][v]+n.first;
                q.push(make_pair(dist[x][n.second],n.second));
            }
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int N;
    cin>>N;
    vector<pair<int,int> > graph[N+1];
    unordered_map<string,int> m;
    for(int i=0;i<=N;i++)
    graph[i].clear();
    m.clear();
    for(int i=1;i<=N;i++)
    {
        string s; // name of this node
        cin>>s;
        m[s]=i;

        int p;
        cin>>p;

        while(p--)
        {
            int neighbour,cost;
            cin>>neighbour>>cost;
            graph[i].push_back(make_pair(cost,neighbour));
        }
    }

    memset(done,0,sizeof(done));
    memset(dist,2e5,sizeof(dist)); // all the distances are set to infinity (in this case it is MAX=200000)

    int r;
    cin>>r;

    while(r--)
    {
        string s1,s2;
        cin>>s1>>s2;

        int a,b;
        a=m[s1],b=m[s2];
        if(done[a]) cout<<dist[a][b];
        else if(done[b]) cout<<dist[b][a];
        else
        {
            dijkstra(dist,graph,a);
            cout<<dist[a][b];
        }
        
        if(r)
        cout<<endl;
    }
  }
}