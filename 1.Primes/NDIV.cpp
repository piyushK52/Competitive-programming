//User will enter a,b,n. You have to find all the numbers between a and b (both inclusive) that have n factors.


#include <iostream>
using namespace std;

int check[32000];   //size is sqrt(10^9)
int prime[10000];   //no. of primes will be significantly less

//In this program we are finding prime factors of 10^9 order no.s
//First we will find prime no. less than sqrt(10^9) as factors are always less than sqrt(n)

void sieve()
{
    //a number can be struck off only by its factor which will be less than sqrt(n)
    //since prime numbers are always odd we are checking only the odd ones
    for(int i=3;i<=180;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=32000;j+=i)      //i*(i-1), i*(i-2) etc will be already checked before this
            check[j]=1;
        }
    }

    prime[0]=2;   //since prime[1] will be 3 and 2 is the only even prime therefore it is put in zeroth position.
    int j=1;
    for(int i=3;i<=32000;i+=2)
    {
        if(!check[i])
        prime[j++]=i;     //we arrange the primes in a list
    }
}

int main()
{
    sieve();
    int a,b,n,temp,total=1,res=0;
    cin>>a>>b>>n;
    int count=0,i,j,k;

    for(i=a;i<=b;i++)
    {
        temp=i;
        total=1;
        k=0;
        //***************MEMBLOCK**************    // O(sqrt(N))
        for(j=prime[k];j*j<=temp;j=prime[++k])     //we are only checking primes less than sqrt(n) {for finding prime factors}
        {                                          //because there can be only a single prime with degree one after sqrt(n)
            count=0;                               // proof (rough): a*b=n => you have found out a (as combination of primes less than sqrt(n))
            while(temp%j==0)                       // => b will be greater than sqrt(n)
            {                                      // => if j>sqrt(n) then j^2>n => not possible => j will be of order atmost 1
                count++;                           // => so if temp doesn't becomes 1 after loop we multiply the total by 2 {which is basically (1+1) like (power_of_prime+1)}
                temp/=j;                           // eg. 34=2*17
            }
            total *=count+1;
        }
        //**************************************
        if(temp!=1)
            total*=2;
        
        if(total==n)
            {
                res++;
            }
    }
    cout<<res<<endl;
    return 0;
}
    
//We have to find all the prime factors of numbers upto 10^9
//We first find all the prime no.s that can be its factor (prime numbers less than 32000)
//We then find the order of each prime factor say a,b,c...
//Then the total no. of factors in (a+1)*(b+1)*(c+1)...