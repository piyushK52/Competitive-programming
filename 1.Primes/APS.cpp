#include <iostream>
#include <string.h>
using namespace std;

int f[10000010];
long long int res[10000010];

void find_bigf()
{
    int i;
    
    for(i=2;i<=10000000;i++)
    {
         if(f[i]==-1)                //if the smallest prime factor of the number has not yet been found then it is the number itself
         {
            f[i]=i;
            res[i]=res[i-1]+i;
            for(int k=2*i;k<=10000000;k+=i)
            if(f[k]==-1)
            f[k]=f[i];
         }
         else
         res[i]=res[i-1]+f[i];
     }
}
int main()
{
    fill_n(f,10000003,-1);
    f[0]=f[1]=0;
    res[0]=res[1]=0;
    find_bigf();
    int t;
    for(cin>>t;t;t--)
    {
        int n;
        cin>>n;
        //cout<<"n is: "<<n<<endl;
        cout<<res[n]<<endl;
    }
}

//You have to print the sequence given in the question
//Steps:
//Sieve (two loops of full length)
//1. We will precalculate the smallest prime divisor for every no. beforehand.
//   => We use sieve. We mark every no. as -1 (meaning not checked) while looping if a no. is not checked
//      it means that it is the smallest prime divisor (SPD) of itself. We then mark all its multiples 
//      (which means this now becomes the SPD of them) if they are not previously marked (imp***).


