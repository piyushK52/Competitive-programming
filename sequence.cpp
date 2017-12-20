#include<bits/stdc++.h>
using namespace std;
long long f[5001];
int a[5001],b[5001];
int main()
{
	int i,j,n;
	cin>>n;
    memset(f,0,sizeof f);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            f[j]+=abs(a[i]-b[j]); //make it equal to b[i]
            if(j>1)
            f[j]=min(f[j-1],f[j]); //if making it equal to b[i-1] is cheaper than do that
        }//for(int k=1;k<=n;k++) cout<<f[k]<<" ";cout<<endl;}
        cout<<f[n];
    return 0;
}  