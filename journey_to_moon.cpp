#include<bits/stdc++.h>
using namespace std;
//#define MOD 1e10
int n,m,checked[100010];
long long int total=1,old_sum=0,num,MOD=1e10;
vector<int> adj[100010];
void dfs(int i)
{
    if(!checked[i])
    {
        num++;
        checked[i]=1;
        for(int a=0;a<adj[i].size();a++)
        dfs(adj[i][a]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
      int x,y; cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    
    for(int i=0;i<n;i++)
    {
      num=0;
      if(!checked[i])
      dfs(i);
      if(num!=0)
      total+=old_sum*num;
      if(total>MOD)
      total=total-MOD;
      old_sum+=num;
      if(old_sum>MOD)
      old_sum=old_sum-MOD;
    }

    cout<<total-1<<endl;

}