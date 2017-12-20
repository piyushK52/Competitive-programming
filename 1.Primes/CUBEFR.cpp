#include<iostream>
using namespace std;
int A[1000001]={0};   //0 means cube free, A[i]=0 means that i^3 is not checked
void cube_free()
{
 int i,k,j;
 for(i=2;i*i*i<=1000000;i++) // checking for 2^3,3^3...    // O(n^1/3)
 {
  if(A[i]==0)
  {
   k=i*i*i;
   for(j=k;j<=1000000;j+=k) //marking multiples of 2^3,3^3... // O(loglog n)
    A[j]=-1;
  }
 }
 k=1;
 for(i=1;i<=1000000;i++)
  if(A[i]==0)
   A[i]=k++;
}
int main()
{
 cube_free();
 int t,n;
 cin>>t;
 for(int i=1;i<=t;i++)
 {
  cin>>n;
  if(A[n]!=-1)
   cout<<"Case "<<i<<":"<<" "<<A[n]<<endl;
  else
   cout<<"Case "<<i<<":"<<" Not Cube Free"<<endl;
 }
 return 0;
}

//You have to find all the no.s such that none of its divisors are cube of any no. Then you have to
//arrange them in a list and when asked about a certain no. you have to return its position in the list or output "impossible"
//steps:
//Sieve
//1. We mark every no. 0 (meaning cube free). We loop through 1^3,2^3... if a no. is cube free then we marks all of its
//   multiples as not cube free.
//2. We now have all the cube free no., just loop through them and give each of them a serial.