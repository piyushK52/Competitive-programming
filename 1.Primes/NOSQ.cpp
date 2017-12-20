//find the no. of integers between given two no.s which are square free and contains a given digit in them
//algo - pre-computation
#include <stdio.h>
using namespace std;
int A[100000][11]={0};  //first bracket stores no. and second stores digit (if it is from 0-9, 10th bit gives if that no. is square free or not) 
void sqfree()        
{
 int i,temp;
 int k,j;
 A[0][0]=1;
 for(i=2;i*i<=100000;i++)   // checking no. like 2^2,3^2...
 {
  if(A[i][10]==0)         //if a no. is square free then all the multiples of its square are not square free.
  {
   k=i*i;
   for(j=k;j<=100000;j+=k)
     A[j][10]=1;
  }
 }
 
 for(i=1;i<=100000;i++)
 {
  if(A[i][10]==0){
   temp=i;
   while(temp!=0)
   {
    A[i][temp%10]=1;
    temp/=10;
   }
   for(j=0;j<=9;j++)
   {
    A[i][j]+=A[i-1][j];
   }
  }
  else
   for(j=0;j<=9;j++)
    A[i][j]=A[i-1][j];
 }
}
int main()
{
 int t;
 sqfree();
 scanf("%d",&t);
 while(t--)
 {
  int low,high,digit;
  scanf("%d%d%d",&low,&high,&digit);
  printf("%d\n",A[high][digit]-A[low-1][digit]);
 }
 return 0;
}
