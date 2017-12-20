// You have to find the power of primes in n!
#include <iostream>
using namespace std;

int prime[10001];                            //here we will need primes upto n, since n also comes in n!
void sieve()
{
	prime[10001] = {0}; //0 means that the number is prime

	for (int i = 2; i <= 100; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j < 10001; j += i)
				prime[j] = 1;
		}
	}

	/*cout<<"printing all the prime numbers: "<<endl;
	for(int i=2;i<=101;i++)
	if(prime[i]==0)
	cout<<i<<" ";
	cout<<endl;*/
}
int order(int a, int n)              // finding order of number a in n!
{                                    // power of a in n! will be n/a + n/a^2 ...
                                     // think of it as n/a gives no. of times a comes in n
	int ans = 0;                     // (n/a)/a gives no. of times a comes in n/a and so on
	while (n > 0)
	{
		ans += n / a;
		n = n / a;
	}
	return ans;
}
int main()
{
	sieve();
	int n;
	while (cin >> n)
	{
		for (int i = 2; i <= n; i++)
		{
			while (prime[i] != 0)
			{
				i++;
			}

			if (i <= n)
			{
				if(i!=2)
				cout <<" * "<< i << "^" << order(i, n) ;
				else
				cout << i << "^" << order(i, n) ;
			}
		}
		cout<<endl;
	}
}