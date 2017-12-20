#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n,k,x;
  int a[200000];
  cin>>n>>x>>k;
  for (int i = 1; i <= n; i++) 
  cin>>a[i]; 
  sort(a + 1, a + n + 1); 
	ll  total = 0; 

	for (int i = 1; i <= n; i++) 
  {
    ll  c = ((a[i] - 1) / x);
    ll  d = k + c; 
    ll  lv = max(1ll  * a[i], d * x); 
    ll  hv = d* x + (x - 1); 
    int idx_l = lower_bound(a + 1, a + n + 1, lv) - a; 
    if (a[idx_l] > hv) { continue; }
    int idx_h = upper_bound(a + 1, a + n + 1, hv) - a; 
    total += (ll)idx_h - idx_l;
  }
  cout<<total;
  return 0;
}
        