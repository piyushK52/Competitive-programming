#include<bits/stdc++.h>
using namespace std;
int n,k,num=0,M=0,checked[310];
vector<int> adj[310],arr[310];
void display(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
}
bool compare(vector<int> a,vector<int> b)
{
    int cal=0;
    for(int i=0;i<a.size();i++)
     for(int j=0;j<b.size();j++)
      if(a[i]==b[j])
      cal++;
      if(cal>=k)
      return true;
      return false;
}
void dfs(int i)
{
    //cout<<"checking "<<i<<endl;
    if(!checked[i])
    {
        checked[i]=1;
        ++num;
        for(int a=0;a<adj[i].size();a++)
        dfs(adj[i][a]);
    }
}
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int n1;cin>>n1;
    arr[i].resize(n1);
    for(int j=0;j<n1;j++)
    cin>>arr[i][j];
    for(int l=1;l<i;l++)
    if(compare(arr[i],arr[l]))
    {
        //cout<<"match of "<<i<<" found with "<<l<<endl;
        adj[i].push_back(l);
        adj[l].push_back(i);
    }
  }

  for(int i=1;i<=n;i++)
   {
    if(!checked[i])
    dfs(i);
    M=max(M,num);
    num=0;
   }

   cout<<M<<endl;
   //cout<<"*****"<<adj[1].size();
}