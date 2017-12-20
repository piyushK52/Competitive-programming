#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if(abs(ax-bx)+abs(ay-by)==abs(bx-cx)+abs(by-cy))
    {
        int y1=ay-by,x1=ax-bx,y2=by-cy,x2=bx-cx;
        int g1=gcd(y1,x1),g2=gcd(y2,x2);
        y1/=g1,x1/=g1,y2/=g2,x2/=g2;
        if((y1*x1>=0&&y2*x2>=0&&abs(y1)==abs(y2)&&abs(x1)==abs(x2))||(y1*x1<0&&y2*x2<0&&abs(y1)==abs(y2)&&abs(x1)==abs(x2)))
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}