#include <bits/stdc++.h>
using namespace std;

int stree[4 * 1000000];
int arr[1000000], sortarr[1000000];

int sum_query(int node, int left, int right, int qleft, int qright) 
{
  if (right < qleft || left > qright) // if query range is outside the array range
    return 0;

  if (qleft <= left && qright >= right) // if there is total overlap then you return the node
    return stree[node];
  
  // for partial overlap
  int sm = 0;
  int mid = (left + right) / 2;
  sm += sum_query(2 * node + 1, left, mid, qleft, qright);
  sm += sum_query(2 * node + 2, mid + 1, right, qleft, qright);
  return sm;
}

void update_tree(int node, int left, int right, int updex) 
{
  if (left == right && updex == left) // if update index is found we set it to 1
  {
    stree[node] = 1;
    return;
  }

  if (updex < left || updex > right) // if it is out of range then we return, without updating anything
    return;

  int mid = (left + right) / 2;
  update_tree(2 * node + 1, left, mid, updex);
  update_tree(2 * node + 2, mid + 1, right, updex);
  stree[node] = stree[2 * node + 1] + stree[2 * node + 2]; // we also update the value of all the nodes along the way
}

int main() 
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) 
  {
    cin >> arr[i];
    sortarr[i] = arr[i];
  }

  sort(sortarr, sortarr + n);

  for (int i = 0; i < n; i++) 
  {
    int sdex = lower_bound(sortarr, sortarr + n, arr[i]) - sortarr; 
    // 1. for using lower bound array should already be sorted in ascending order
    // 2. objects in the [first,last) are accessed
    // 3. lower bound - returns an iterator pointing to the first element which is arr[i]
    // 4. upper bound - returns an iterator pointing to the first element which is not arr[i]
    // 5. here difference of memory address of arr[i] and arr[0] gives its index
    int rank = sum_query(0, 0, n - 1, sdex + 1, n) + 1;
    cout << rank << "\n";
    // Number of things more than this element
    // + 1
    update_tree(0, 0, n - 1, sdex);
  }
  
  cout<<"displaying the tree:"<<endl;
  for(int i=0;i<2*n+10;i++)
  cout<<stree[i]<<" ";
  cout<<endl;
  return 0;
}

/*
overall complexity - n(n+logn) => n^2
*/