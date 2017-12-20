#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2!=0)
    {
      int first=3,last=3;
      for(int i=0;i<n;i++)
      {
          int temp;cin>>temp;
          if(i==0)
          first=temp;
          else if(i==n-1)
          last=temp; 
      }
      if(first%2==0||last%2==0)
      {cout<<"No"<<endl; exit(0);}
      cout<<"Yes"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {int t;cin>>t;}
        cout<<"No"<<endl;
    }
}