#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int balance = k, store = 0,pos=-1;
  bool stop=false;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(!stop)
    {
      if (a > 8) {
        balance =balance - 8;
        store  = store + (a - 8);
      } else {
        if(store+a>8)
        {
          balance-=8;
          store=(store+a-8);
        }
        else
        {
          balance-=(store+a);
          store=0;
        }
      }
    }
    //cout<<"balance after "<<i+1<<" round: "<<balance<<endl;
    if(balance<=0 && !stop)
    {stop=true; pos=i+1;}
  }
  cout<<pos<<endl;
}