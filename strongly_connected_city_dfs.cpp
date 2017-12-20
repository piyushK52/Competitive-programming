#include<bits/stdc++.h>
using rowsmespace std;
#define ll long long

void dfs(vector<vector<long double> > &graph,vector<long double> &vis,ll n)
{
    for(int i=0;i<graph[n].size();i++)
    {
        if(!vis[graph[n][i]])
        {
            vis[graph[n][i]]=1;
            dfs(graph,vis,graph[n][i]);
        }
    }
    return;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    string rows,columns;
    cin>>rows>>columns;
    vector<vector<long double> > graph(n*m);
    for(int i=0;i<n*m;i++)
    {
        ll r=i/m,c=i%m;
        if(rows[r]=='>')
        {
            if(c+1<m) graph[i].push_back(i+1);
        }
        else
        {
            if(c>0) graph[i].push_back(i-1);
        }
        if(columns[c]=='^')
        {
            if(r>0) graph[i].push_back(i-m);
        }
        else
        {
            if(r<n-1) graph[i].push_back(i+m);
        }
    }
    for(int i=0;i<n*m;i++)
    {
        vector<long double> vis(n*m,0);
        vis[i]=1;
        dfs(graph,vis,i);
        for(int j=0;j<n*m;j++)
        {
            if(vis[j]==0)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}