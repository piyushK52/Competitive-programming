#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100100;
ll pos[N], neg[N], a[N];
vector<int> adj[N];
int n;

void dfs(int x, int from) 
{
  pos[x] = neg[x] = 0;
  for (auto y : adj[x])
    if (y != from) 
    {
      dfs(y, x);
      pos[x] = max(pos[x], pos[y]);
      neg[x] = max(neg[x], neg[y]);
    }
  a[x] += neg[x];
  a[x] -= pos[x];
  if (a[x] > 0) 
  {
    pos[x] += a[x];
    a[x] = 0;
  }
  if (a[x] < 0) 
  {
    neg[x] -= a[x];
    a[x] = 0;
  }
}

int main() {

  cin >> n;
  for (int i = 1; i < n; i++) 
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dfs(1, 0);
  cout << (pos[1] + neg[1]);

  return 0;
}