#include <bits/stdc++.h>
using namespace std;
const int MX = 3009;
int U[MX], V[MX], W[MX], dis[MX];
int n, m, T, Tn;
int ans[MX];
vector<int> adj[MX];

int main() 
{
  scanf("%d", &T);
  while (T--) 
  {
    scanf("%d %d", &n, &m);
    for (int j = 1; j <= n; j++) 
    {
      dis[j] = 1e9; // setting distances to infinity
      adj[j].clear();
      ans[j] = 0;
    }

    for (int j = 1; j <= m; j++) 
    {
      scanf("%d %d %d", &V[j], &U[j], &W[j]);
      ++U[j], ++V[j];
      adj[U[j]].push_back(V[j]); // graph stored in reverse order
    }
    
    /*cout<<"displaying the adjacency list: "<<endl;
    for(int i=1;i<=n;i++)
     {
       for(int j=0;j<adj[i].size();j++)
       cout<<adj[i][j]-1<<" ";
       cout<<endl;
     }*/
    int ok = 1;
    for (int iter = 1; iter < n && ok; iter++) // if you find all the shortest path 
    { // in one go then you don't need to repeat it again, ok takes care of that
      ok = 0;
      for (int j = 1; j <= m; j++) 
       if (dis[V[j]] > dis[U[j]] + W[j]) 
        {
          dis[V[j]] = dis[U[j]] + W[j];
          ok = 1;
        }
    }
    vector<int> cycle;
    for (int j = 1; j <= m; j++) // the mth operation to check if there is a cycle
      if (dis[V[j]] > dis[U[j]] + W[j]) // if the distance from u to v decreases
      {
        cycle.push_back(U[j]); // then we first push u
        cycle.push_back(V[j]); // and then v
      }

    printf("Case %d: ", ++Tn);
    if (cycle.empty()) 
    {
      puts("impossible");
      continue;
    }
    queue<int> Q;
    for (auto node : cycle)
      Q.push(node);    // push all the potential that form a cycle in a queue

    while (!Q.empty()) // we find all the nodes reachable from potential nodes
    { // which basically will form the cycle
      int cur = Q.front();
      Q.pop();
      if (ans[cur])
        continue;
      ans[cur] = 1; // mark all the cycle node, there can be node which is not a part of the cycle but it is pointing
      for (auto nxt : adj[cur]) // at it
        Q.push(nxt);//cout<<"***"<<nxt-1<<endl;}
    }
    vector<int> sol;
    for (int j = 1; j <= n; j++)
      if (ans[j])
        sol.push_back(j); 
    for (int j = 0; j < sol.size(); j++) 
    {
      if (j)
        cout << ' ';
      cout << sol[j] - 1;
    }
    puts("");
  }
}