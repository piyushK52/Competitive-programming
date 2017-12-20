#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[4],b[4],c[4];
        for(int i=1;i<=3;i++)
        cin>>a[i]>>b[i]>>c[i];
        int flag=1;
        if((a[1]==a[2]&&b[1]==b[2]&&c[1]==c[2])||(a[1]==a[3]&&b[1]==b[3]&&c[1]==c[3])||(a[3]==a[2]&&b[3]==b[2]&&c[3]==c[2]))
        cout<<"no"<<endl;
        else
        {
            
            if(!((a[1]>=a[2]&&b[1]>=b[2]&&c[1]>=c[2])||(a[1]<=a[2]&&b[1]<=b[2]&&c[1]<=c[2])))
            flag=0;//cout<<"1st";}

            if(!((a[3]>=a[2]&&b[3]>=b[2]&&c[3]>=c[2])||(a[3]<=a[2]&&b[3]<=b[2]&&c[3]<=c[2])))
            flag=0;//cout<<"2nd";}

            if(!((a[1]>=a[3]&&b[1]>=b[3]&&c[1]>=c[3])||(a[1]<=a[3]&&b[1]<=b[3]&&c[1]<=c[3])))
            flag=0;//cout<<"3rd";}
            
            if(flag==0)
            cout<<"no"<<endl;
            else
            cout<<"yes"<<endl;
            
        }
    }
}