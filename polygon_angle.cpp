#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x,a,min,n;
    cin >> n >> a;
    x=180/n;min=180;
    int v=n;
    
    for(double i=3; i<=n; i++){
        if(abs(x-a)<min){
            v=i;
            min=abs(x-a);
        }
        x+=(180/n);
    }
    cout << "2 1 "<< v;
    return 0;
};