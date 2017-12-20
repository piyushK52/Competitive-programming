#include <bits/stdc++.h>
using namespace std;

void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char a[], int l, int r)
{
    if(l==r)
    cout<<a<<endl;
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a+l,a+i);
            permute(a,l+1,r);
            swap(a+l,a+i);
        }
    }
}
int main()
{
    char a[50];
    int size;
    cin>>a>>size;
    permute(a,0,size-1);
}