#include <bits/stdc++.h>
using namespace std;

#define ll long long
bool grid[310][310];
ll dp[310][310][310][2];

ll d, r, c;

ll solve(ll i, ll j, ll cover, bool dn) {
  if (i == r - 1 && j == c - 1)
    return 1;

  if (i >= r || j >= c || grid[i][j] == 0)
    return 0;

  if (dp[i][j][cover][dn] != -1)
    return dp[i][j][cover][dn];

  ll x = 0;

  if (dn == 1) 
  {
    if (cover < d)
      x = (x + solve(i + 1, j, cover + 1, 1)) % 20011;
    x = (x + solve(i, j + 1, 1, 0)) % 20011;
  } 
  else 
  {
    x = (x + solve(i + 1, j, 1, 1)) % 20011;
    if (cover < d)
      x = (x + solve(i, j + 1, cover + 1, 0)) % 20011;
  }

  return dp[i][j][cover][dn] = x;
}

int main() {
  ll cs, t, i, j, k, x, y, z, ans, q, m;

  cin >> r >> c >> d;

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0, 0, 0, 0);

  return 0;
}