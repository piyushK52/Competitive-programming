#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int n,m,k;
char matrix[501][501];
bool visited[501][501];

void dfs(int i,int j)
{
    visited[i][j]=1;
    int x,y;
    for(int c=0;c<4;c++)
    {
        x=i+dir[c][0];y=j+dir[c][1];
        if(x>=0 && x<n && y>=0 && y<m && matrix[x][y]=='.' && !visited[x][y])
         dfs(x,y);
    }
    if(k)
    {k--;matrix[i][j]='X';}
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    cin>>matrix[i];

	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
      if(matrix[i][j]=='.')
       {
          dfs(i,j);
          break;
       }
    
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
        cout<<matrix[i][j];
       cout<<endl;
    }
return 0;
}