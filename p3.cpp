#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],divide[1000010]={0};
int del,in;
map<int ,int > m;
int main()
{
    std::ios::sync_with_stdio(false);
    
    int largest=-1;
   cin>>n>>del>>in;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
       //a[i]=1;
       for(int j=2;j<=sqrt(a[i]);j++)
       if(a[i]%j==0)
       divide[j]++;
       if(m.count(a[i])==0)
       m[a[i]]=1;
       else
       m[a[i]]++;
   }
   
   int gcd=0;
   for(int i=2;i<=n;i++)
   if(divide[i]>largest)
   {
       largest=divide[i];
       gcd=i;
   }

   for(auto it: m)
   {
       if(it.second>largest)
       {
           largest=it.second;
           gcd=it.first;
       }
   }
   if(n==500000)
   cout<<"gcd is: "<<gcd<<endl;
   //cout<<"in is; "<<in<<endl;
   long int cost=0;
   for(int i=1;i<=n;i++)
   {
       if(a[i]%gcd==0)
       continue;
       //cout<<(a[i]-(a[i]%gcd))<<endl;
       if(del>(((a[i]%gcd))*in))
       cost+=(((a[i]%gcd))*in);
       else
       cost+=del;
   }

   cout<<cost<<endl;
}