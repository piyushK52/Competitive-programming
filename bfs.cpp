#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
int dd, d[2]={0},v[100]={0};

void bfs(int a)                                                                                                                                                                                                                                                                                                                  
{
    queue<int> Q;
    Q.push(a);
    dd=1;
	while (!Q.empty())
	{	
       dd^=1;
       int n=Q.front();
       if(v[n]==0)
       v[n]++;
       else
       continue;
       Q.pop();
       d[dd]++;
       for(int i=0;i<g[n].size();i++)
       {
         if(v[g[n][i]]==0)  
         Q.push(g[n][i]);
       }
	}
}

int main()
{
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    cout<<d[0]+d[1];
}
