#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,sum=0,carry=0,a;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a;
        sum+=a%2==0 ? a:a+1;
        carry+=a%2==0 ? 0:1;
    }

    if(sum>8*n)
    cout<<"NO"<<endl;
    else if(sum==8*n)
    {
        if(k==4*n&&carry<n)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    else
    cout<<"YES"<<endl;
}