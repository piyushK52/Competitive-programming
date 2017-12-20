#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[160];
ll n;
ll dp[160][45010];

ll solve(ll i, ll make) {
  if (i >= n||make<=0)
    return 0;

  if (dp[i][make] != -1)
    return dp[i][make];

  dp[i][make] = solve(i + 1, make);

  if (make - a[i] >= 0) {
    dp[i][make] = max(dp[i][make], solve(i + 1, make - a[i]) + a[i]);
  }

  return dp[i][make];
}

int main() {
  ll t, i, j, k, x, y, sum;
  cin >> n;
  sum = 0;

  for (i = 0; i < n; i++) {
    cin >> x;
    cin >> y;
    a[i] = x - y;
    if(a[i]<0)
    a[i]*=-1;
    sum += a[i];
  }
  x = sum / 2;
  memset(dp, -1, sizeof(dp));
  i = solve(0, x); //finds maximum achievable sum from the elements <='sum/2'
  j = sum - i; //sum of other subset
  cout << abs(i - j); //overall difference of the subsets
  return 0;
}
/*
The task is to divide the set into two parts. 
We will consider the following factors for dividing it. 
Let 
  dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum 
                      equal to j
                   0 otherwise}
    
    i ranges from {1..n}
    j ranges from {0..(sum of all elements)}  

So      
    dp[n+1][sum+1]  will be 1 if 
    1) The sum j is achieved including i'th item
    2) The sum j is achieved excluding i'th item.

Let sum of all the elements be S.  

To find Minimum sum difference, w have to find j such 
that Min{sum - j*2  : dp[n][j]  == 1 } 
    where j varies from 0 to sum/2

The idea is, sum of S1 is j and it should be closest
to sum/2, i.e., 2*j should be closest to sum.
*/