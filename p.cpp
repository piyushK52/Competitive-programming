#include <bits/stdc++.h>
using namespace std;

long long dotProduct(vector <long long> a,vector <long long> b,vector <long long> c)
{
    long long ans=0;
    for(int i=0;i<5;i++)
        ans+=(b[i]-a[i])*(c[i]-a[i]);
    return ans;
}

int main()
{
    long long n,i,j,k;
    scanf("%lld",&n);
    if(n==1)
    {
        printf("1\n1");
        return 0;
    }
    if(n==2)
    {
        printf("2\n1\n2");
        return 0;
    }
    vector <long long> point[n];
    for(i=0;i<n;i++)
    {
        long long temp;
        for(j=0;j<5;j++)
        {
            scanf("%lld",&temp);
            point[i].push_back(temp);
        }
    }
    bool foundGood=false;
    for(i=0;i<n;i++)
    {
        bool isGood=true;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(i!=j && j!=k && k!=i && dotProduct(point[i],point[j],point[k])>0)
                {
                    isGood=false;
                    break;
                }
            }
            if(!isGood)
                break;
        }
        if(isGood)
        {
            foundGood=true;
            break;
        }
    }
    if(foundGood)
        printf("1\n%d",i+1);
    else
        printf("0");
}