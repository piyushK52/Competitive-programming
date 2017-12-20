#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[200010];

multiset<ll> pq;
multiset<ll>::iterator it;

int main() {
  ll cs, t, i, j, k, x, y, z, ans, q, m, n;

  cin >> n;

  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pq.insert(a[i] + i); // adding 1,2,3...N to the current array
  }

  for (j = 1; j <= n; j++) {
    if (j != 1)  // providing spaces except for the first element
      printf(" ");

    it = pq.end();
    printf("%lld", *(--it) + j - 1); // we print the incresed value of the largest

    it = pq.find(a[n - j + 1] + n - j + 1); // at iteration 'j' a[t] will decrease by n-1
    // In the initial array its value is a[t]+t
    pq.erase(it); 

    pq.insert(a[n - j + 1] + n - j + 1 - n); // we erase a[t]+t and replace it with a[t]+t-n
  }

  cout << endl;

  return 0;
}