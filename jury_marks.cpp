#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,n,t,a[2005]={};
	set<int> c;
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++) scanf("%d",&t),a[i]=a[i-1]+t;
    for(int i=0;i<n;i++)
    {
		scanf("%d",&t);
		set<int> mmp;
        for(int j=1;j<=k;j++)
        {
			int x=t-a[j];
            if(!i||c.find(x)!=c.end()) // insert every 'x' for 1st b, after that check if 'x' is already present or not 
            mmp.insert(x); 
		}
		c=mmp; //this becomes the new map
	}
	cout<<c.size();
	
return 0;
}