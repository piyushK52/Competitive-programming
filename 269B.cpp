//finding maximum non-decreasing subsequence
#include <bits/stdc++.h>
using namespace std;
int s[5010], dp[5010], n, m;
long double x[5010];
int solve() {
  if (n == 1 || n == 0)
    return n;
  dp[1] = 1; //longest non-decreasing subsequence till now
  int maxans = 0;
  for (int i = 2; i <= n; i++) 
  {
    int maxval = 0;
    for (int j = 1; j < i; j++) 
    {
      if (s[i] >= s[j]) // for longest increasing subsequence just replace >= with >
      maxval = max(maxval, dp[j]);  
    }
    dp[i] = maxval + 1; // at the index 'i' there will always be LNIS of length one
    maxans = max(maxans, dp[i]);
  }
  return maxans;
}

int main() 
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> s[i] >> x[i];
  cout << n - solve() << endl;
}