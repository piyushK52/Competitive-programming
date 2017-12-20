#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, dp1[1200][1200], dp2[1200][1200], dp3[1200][1200],
    dp4[1200][1200], a[1200][1200], temp, ans;

int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      cin >> a[i][j];

for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]); // dp1[i][j] => max gain in going from (1,1) to (i,j)
  // starting from (1,1) we are following inverted steps, instead of down and
  // right we are going up and left
  for (int j = m; j >= 1; --j)
    for (int i = 1; i <= n; ++i)
      dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]); // dp2[i][j] => max gain in going from (i,j) to (1,m)
  for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
      dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]); // dp3[i][j] => max gain in going from (n,1) to (i,j)
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
      dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]); // dp4[i][j] => max gain in going from (i,j) to (n,m)
  ans = -1;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++) {
      temp = max(dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1],
                 dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j]);
      if (temp > ans)
        ans = temp;
    }
  cout << ans << endl;
}


// READ TUTORIAL PROBLEM 429B
// http://codeforces.com/blog/entry/12265