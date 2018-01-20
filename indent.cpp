#include<bits/stdc++.h>
//#define MI 100000007
using namespace std;

int main()
{
	char c,p;
	int n,blocks=0;
	cin>>n;
	int t=n;
	while(t--)
	{
		cin>>c;
		if(t==n-1&&c=='f')
		blocks++;
		else if(p!=c&&c=='f')
		blocks++;
		p=c;
	}
	
	cout<<pow(2,blocks-1);
}
