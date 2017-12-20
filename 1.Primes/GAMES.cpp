#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int gcd(int a,int b)   //euclid's gcd  complexity-  O(log n)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    for(cin>>n;n;n--)
    {
        char a[12], b[4];
        memset(b, '0', 4);

        cin >> a;
        for (int i = 0, found = 0, k = 0; i < strlen(a); i++)
        {
            if (found == 1)
            {
                b[k++] = a[i];
            }
            else if (a[i] == '.')
            {
                found = 1;
            }
        }

        int t = 0;
        for (int j = 0; j < 4; j++)
        {
            t = 10 * t + (b[j] - '0');
        }

        if(t!=0)
        while (t % 10 == 0)
            t = t / 10;
        
        int temp=t,size=0;
        while(temp!=0)
        {
            ++size;
            temp=temp/10;
        }

        int n1=pow(10,size);

        int g=gcd(n1,t);
        cout<<n1/g<<endl;
    }
}

//In this question you have to basically find an integer which when multiplied by a given fraction (given in .2457 form)
//gives an integer.
//steps:
//1. You find the fractional part (.256) find the gcd of this with power of hundred (256 and 1000 in this case), final
//   answer is 1000/gcd.
//2. The new thing here is finding gcd, the solution used here is very elegant.