#include <bits/stdc++.h>
using namespace std;

// Binary search (note boundaries in the caller)
int CeilIndex(vector<int> &v, int l, int r, int key) 
{ // search space is of the form 0000000011111111111
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if (v[m] >= key)
      r = m;
    else
      l = m;
  }

  return r; // l gives the first 0 element and r gives the first 1 element
}

int LIS(vector<int> &v) 
{
  if (v.size() == 0)
    return 0;

  vector<int> tail(v.size(), 0);
  int length = 1; // always points empty slot in tail

  tail[0] = v[0];
  for (int i = 1; i < v.size(); i++) 
  {
    if (v[i] < tail[0]) // new smallest value
      tail[0] = v[i];
    else if (v[i] > tail[length - 1]) // v[i] extends largest subsequence
      tail[length++] = v[i];
    else
      tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
      // v[i] will become end candidate of an existing subsequence or
      // Throw away larger elements in all LIS, to make room for upcoming greater
      // elements than v[i]
      // (and also, v[i] would have already appeared in one of LIS, identify the
      // location and replace it)
      
  }

  return length;
}

int main() {
  vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
  cout << "Length of Longest Increasing Subsequence is " << LIS(v) << endl;
  return 0;
}