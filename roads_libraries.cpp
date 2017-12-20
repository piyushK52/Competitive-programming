#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> adj[100010];

bool vis[100010];

ll node;

void dfs(ll n) {
  node++;
  vis[n] = 1;

  for (ll i = 0; i < adj[n].size(); i++) {
    ll v = adj[n][i];
    if (vis[v] == 0) {
      dfs(v);
    }
  }
}

int main() {
  ll cs, t, i, j, k, x, y, z, ans, q, m, n, p;

  cin >> t;

  for (cs = 1; cs <= t; cs++) {
    cin >> n >> m >> p >> q;

    memset(vis, 0, sizeof(vis));

    for (i = 1; i <= n; i++)
      adj[i].clear();

    for (i = 1; i <= m; i++) 
    {
      cin >> x;
      cin >> y;

      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    ans = 0;

    for (i = 1; i <= n; i++) 
    {
      if (vis[i] == 0) 
      {
        node = 0;
        dfs(i);
        ans += min(p + q * (node - 1), p * node);
      }
    }

    cout << ans << endl;
  }

  return 0;
}