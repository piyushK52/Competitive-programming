#include <bits/stdc++.h>
using namespace std;
int num[1100000] = {0}, b[1100000] = {0},last;

int MAX() {
  int max = 0;
  for (int i = 0; i < 1100000; i++)
    if (num[i] > max)
      max = num[i];
  return max;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    //last=t1+1;
    b[t1+1] = t2;
  }

  for (int i = 1; i < 1100000; ++i) {
    if (b[i])
      num[i] = num[max(i - b[i] - 1, 0)] + 1;
    else
      num[i] = num[i-1];
  }
  
  //cout<<"max1 is: "<<MAX()<<endl;
  cout << n - MAX() << endl;
}