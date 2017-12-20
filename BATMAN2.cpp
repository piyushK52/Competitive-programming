#include <bits/stdc++.h>
using namespace std;

int dp[103][103][103];
int t,n,a[103],maxx;

int func(int pos,int x,int y) // pos=current position, x=position of last element of incresing sequence, y=last element of decreasing sequence
{
    if(pos==n+1)
    return 0;
    int &ret=dp[pos][x][y]; // ret and dp[pos][x][y] are now one and the same thing
    if(ret!=-1) return ret;
    ret=0;
    if(a[x]<a[pos]) // if the current element is greater than the last element of increasing sequence
      ret = max(ret,func(pos+1,pos,y)+1); // increase position and add this element to the increasing sequence
    if(a[y]>a[pos]) // if the current element is smaller than the last element of decreasing sequence
      ret = max(ret,func(pos+1,x,pos)+1); // increase position and add this element to the decreasing sequence
    return ret = max(ret,func(pos+1,x,y));// return the max of above (considering this element) and not considering this element
}

int main()
{
    cin>>t;
    while(t--)
    {
        maxx=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }
        a[n+1]=maxx+1; // it could have been a very large no. (since limits are not given we are taking max+1)
        cout<<func(1,0,n+1)<<endl;
    }
    return 0;
}