#include<bits/stdc++.h>
using namespace std;

int n;
int answer(vector<int> a)
{
	vector<int> lis(a.size());
    for(int i=0;i<a.size();i++)
	lis[i]=1;

	for(int i=1;i<a.size();i++)
	 for(int j=0;j<i;j++)
	   if(a[i]>a[j] && lis[i]<lis[j]+1)
	   lis[i]=lis[j]+1;

	sort(lis.begin(),lis.end());
	return n-lis[lis.size()-1];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			int b;
			cin>>b;
			a.push_back(b);
		}
		cout<<answer(a);
	}
}