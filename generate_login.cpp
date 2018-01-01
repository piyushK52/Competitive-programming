#include<bits/stdc++.h>
using namespace std;

int main()
{
	string first,last;
	cin>>first>>last;
	string ans;
	int f=0;
	ans += first[0];
	for(int i=1,j=0;i<first.length()&&j<last.length();)
	{
		if(f>0)
		break;
		//{ cout<<"breaking"<<endl;break;}
		if(first[i]<last[j])
		{ ans += first[i]; i++;}
		else
		{
			ans += (last[j]);
			j++;
			f++;
		}
		//cout<<"current i"<<i<<" current j"<<j<<endl;
	}
	if(f==0)
	ans += last[0];
	cout<<ans<<endl;
}
