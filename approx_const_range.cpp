#include <bits/stdc++.h>
using namespace std;
#define N 110000
int similar[N], one_more[N], one_less[N];
// similar=> no. of consecutively attached similars
// ONE=> no. of consecutively attached one less elements
// one_less=> no. of consecutively attached one more elements
int main() 
{
  int a[110000];
  int v = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = n - 1; i >= 0; --i) 
  {
    if (i == n - 1)
      similar[i] = one_more[i] = one_less[i] = 0;
    else if (a[i] == a[i + 1]) 
    {
      similar[i] = 1 + similar[i + 1];
      one_more[i] = one_more[i + 1]; // same no. of one_more and one_less attached to this
      one_less[i] = one_less[i + 1];
    } 
    else if (a[i] == a[i + 1] - 1) // this element is smaller than the element to its right
    {
      similar[i] = 0;
      one_more[i] = one_less[i + 1] + similar[i + 1] + 1; //no. of similar elements to a[i+1] + one less that it
      // one_more is like no. of elements greater than (by 1) or equal to a[i]
      one_less[i] = 0; // no lesser adjacent elements
    } 
    else if (a[i] == a[i + 1] + 1) // this element is greater than the element to its right
    {
      similar[i] = 0;
      one_less[i] = 1 + similar[i + 1] + one_more[i + 1]; //no. of similar elements to a[i+1] + one more than it
      one_more[i] = 0;
    } 
    else 
    {
      similar[i] = 0;
      one_less[i] = 0;
      one_more[i] = 0;
    }
  }
  for (int j = 0; j < n; j++)
    v = max(v, 1 + similar[j] + one_more[j] + one_less[j]);
  cout << v << endl;
}