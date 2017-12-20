#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],c[1010],d[1010],e[1010],n;
bool glist[1010];
bool isgood(int i,int j,int k)
{
    int x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;
    x1=a[j]-a[i],x2=b[j]-b[i],x3=c[j]-c[i],x4=d[j]-d[i],x5=e[j]-e[i];
    y1=a[k]-a[i],y2=b[k]-b[i],y3=c[k]-c[i],y4=d[k]-d[i],y5=e[k]-e[i];
    int z1=x1*y1+x2*y2+x3*y3+x4*y4+x5*y5,z2=x1*x1+x2*x2+x3*x3+x4*x4+x5*x5,z3=y1*y1+y2*y2+y3*y3+y4*y4+y5*y5;
    if(z1>0)
    {
      if(z1*z1<=z2*z3)
      return false;
      return true;
    }
    else
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    
    cin>>n;
   memset(glist,true,sizeof(glist));
   for(int i=1;i<=n;i++)
   cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];

   for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
     for(int k=j+1;k<=n;k++)
     {
         if(!isgood(i,j,k)&&j!=k)
         glist[i]=false;// if(i==1) cout<<"j: "<<j<<" k: "<<k<<endl;}
         if(!isgood(j,i,k)&&i!=k)
         glist[j]=false;
         if(!isgood(k,i,j)&&i!=j)
         glist[k]=false;
     }
     
     int count=0;
     for(int i=1;i<=n;i++)
     if(glist[i]==true)
     count++;
     cout<<count<<endl;

     if(count!=0)
     for(int i=1;i<=n;i++)
     if(glist[i]==true)
     cout<<i<<endl;
}