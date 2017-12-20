#include <bits/stdc++.h>
using namespace std;
int n,m; // n is the no. of fields and m is the number of boats
struct ship {
  int num;
  int len;
  ship(int n, int l) {
    num = n;
    len = l;
  }
};
bool cmp(ship a, ship b) { return a.num < b.num; }
int a[100010];
int MAX(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int MIN(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int dp[100010];
int sum[100010];
vector<ship> b;
int solve(int i, int j)  // i is the field no. and j is the boat no.
{
  if (i >= n || j >= m)
    return 0;
  else if (dp[i] != -1)
    return dp[i];
  else {
    int max = 0;
    int left = b[j].num - b[j].len + 1; // left is the leftmost reachable index
    int right = b[j].num + b[j].len - 1;// right is the rightmost reachable index
    int start = MAX(left, i);
    int end = (j == m - 1) ? n - 1 : b[j + 1].num - 1; // for the last ship you can go to rivers end (n-1)
    // of if you are not the last ship then you can go to the index just before the next ship
    end = MIN(right, end);
    if (end - start + 1 < b[j].len) 
      return -10000000;
    while (end - start + 1 >= b[j].len)  // this loop will finally result in a start and end s.t end-start+1=len
    {
      int s = sum[start + b[j].len - 1] - sum[start-1];
      max = MAX(s + solve(start + b[j].len, j + 1), max);
      start++;
    }
    return dp[i] = max;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i] = 0;
    sum[i] = 0;
    dp[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i == 0)
      sum[i] = a[i];
    else
      sum[i] = a[i] + sum[i - 1];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ship s = ship(x - 1, y);
    b.push_back(s);
  }
  sort(b.begin(), b.end(), cmp);
  int max = solve(0, 0);
  printf("%d\n", max);

  return 0;
}