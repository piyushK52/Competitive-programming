#include<iostream>
using namespace std;
int p[1000009];
long long res[1000009];

void pre()
{
    res[0]=0;res[1]=0;
 for(int i=1;i<=1000000;i++)
 {
   for(int j=i+i;j<=1000000;j+=i)
   {
       p[j]=p[j]+i;} 
  
   res[i]=res[i-1]+p[i];
 }
}
int main()
{
 int t;
 pre();
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  cout<<res[n]<<endl;
 }
 return 0;
}

//steps:
//Sieve 
//1. You have to calculate the sum of all the divisors of a no.
//   => you start the loop from 1,say currently you are at n (maintain an array a[i] for every i) and 
//      add n to all its multiple. this way when you reach the number you will have the sum of all of its multiples.