#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> adj[10000];
ll deg[10000];

int main() {
  ll cs, t, i, j, k, x, y, z, ans, q, m, n;

  cin >> n >> m >> k;

  for (i = 1; i <= m; i++) {
    cin >> x;
    cin >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);

    deg[x]++;
    deg[y]++;
  }

  while (1) {
    for (i = 1; i <= n; i++)
      if (deg[i] < k && deg[i] > 0) // finding first member with non-zero degree less than 'k'
        break;

    if (i == n + 1) 
      break;
    deg[i] = 0; // making its degree zero

    for (j = 0; j < adj[i].size(); j++) // reducing degree of every member connected to it by 1
      deg[adj[i][j]]--;
  }

  ans = 0;

  for (i = 1; i <= n; i++) // counting members with degree >=k
    if (deg[i] >= k)
      ans++;

  if (ans > 0)
    cout << "YES\n" << ans << endl;
  else
    cout << "NO\n";

  return 0;
}