#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1000000007;

ll fact[200010];

ll pwr(ll b, ll p) {
  if (p == 0)
    return 1;

  ll x = pwr(b, p / 2);
  x = (x * x) % mod;

  if (p % 2 == 0)
    return x;
  else
    return (b * x) % mod;
}

int main() {
  ll cs, t, i, j, k, x1, y1, x2, y2, z, ans, q, m, x, y;

  fact[0] = 1;

  for (i = 1; i <= 200001; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  cin >> t;

  for (cs = 1; cs <= t; cs++) {
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    x = x2 - x1;
    y = y2 - y1;

    z = 0;

    // cout<<z<<endl;

    for (i = 0; i <= min(x, y); i++) {
      k = 1;
      k = (k * ((((fact[x + y - i] * pwr(fact[x], mod - 2)) % mod) *
                 pwr(fact[y - i], mod - 2)) %
                mod)) %
          mod; // k=k*ncr(x+y-i,x)
      k = (k * ((((fact[x] * pwr(fact[i], mod - 2)) % mod) *
                 pwr(fact[x - i], mod - 2)) %
                mod)) %
          mod; // k=k*ncr(x,i)

      z = (z + k) % mod;
    }

    printf("Case%lld:%lld\n", cs, z);
  }

  return 0;
}