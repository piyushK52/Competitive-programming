#include<bits/stdc++.h>
using namespace std;
int n,cycle=0,checked[1010];
vector<int> a[1010],adj[1010];
void dfs(int i)
{
   if(!checked[i])
   {
       checked[i]=1;
       a[cycle].push_back(adj[i][0]); 
       dfs(adj[i][0]);
   }
   else
   {
       return;
   }
}
void display(int i)
{
    cout<<a[i][a[i].size()-1]<<" ";
    for(int b=0;b<a[i].size();b++)
    cout<<a[i][b]<<" ";
    cout<<endl;
}

int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       int temp;cin>>temp;
       adj[i].push_back(temp);
   }
   for(int i=1;i<=n;i++) // i denotes the position
   {
       if(!checked[i])
       {
           ++cycle;
           dfs(i);
       }
   }

   cout<<cycle<<endl;
   for(int i=1;i<=cycle;i++)
   display(i);
}