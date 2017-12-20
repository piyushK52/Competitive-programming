#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ima=-1,imi=1000,jma=-1,jmi=1000,r,c,count=0;
    cin>>r>>c;
    char m[110][110];
    for(int i=0;i<r;i++)
     for(int j=0;j<c;j++)
     {
         cin>>m[i][j];
         if(m[i][j]=='B')
         {
             count++;
             if(i<imi)
             imi=i;
             if(i>ima)
             ima=i;
             if(j>jma)
             jma=j;
             if(j<jmi)
             jmi=j;
         }
     }
     //cout<<jma<<" "<<jmi<<" "<<ima<<" "<<imi<<endl;
     if(count==0)
     {cout<<1<<endl;exit(0);}
     int square=max((jma-jmi+1),(ima-imi+1));
     if(square>c||square>r)
     {cout<<-1;exit(0);}
     cout<<square*square-count;
}