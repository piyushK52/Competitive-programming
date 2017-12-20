#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e+9;
int dp[1001][1001], m, n;
vector<int> a, b;

int solve() 
{
  memset(dp,0,sizeof(dp));
  int N = a.size(); // N will be one more because first element is null
  if (N == 0)
    return 0;
  for(int i=2;i<N;++i)
  for(int j=1;j<=m;++j)
  dp[i][j] = MAX;

  for(int j=1;j<=m;++j)
  dp[1][j] = abs(b[1] - a[1]);

  for(int i=2;i<N;++i)
  for(int j=1;j<=m;++j) 
  {
    dp[i][b[i-1]] = min(dp[i][b[i-1]], dp[i-1][j] + abs(j - a[i]) + abs(a[i] - b[i]));
    dp[i][j] =min(dp[i][j], dp[i-1][j] + abs(b[i-1] - a[i]) + abs(a[i] - b[i]));
  }
  int sol = MAX;
  /*for(int i=1;i<N;i++)
   {
     for(int j=1;j<=m;j++)
     cout<<dp[i][j]<<" ";
     cout<<endl;
   }
*/
  for(int j=1;j<=m;++j)
  sol = min(sol, dp[N-1][j]);
  return sol;
}

int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    cin >> m >> n;
    a.resize(0),b.resize(0);
    a.push_back(0),b.push_back(0);
    for (int i = 1; i <= n; ++i) 
    {
      int A, B;
      cin >> A >> B;
      a.push_back(A);
      b.push_back(B);
    }
    cout << solve() << endl;
  }
  return 0;
}