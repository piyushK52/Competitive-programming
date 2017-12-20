#include <bits/stdc++.h>

using namespace std;

int visited[26] = {0};
int g[26][26] = {0};
stack<int> s;

void topological_sort(int v) 
{
  visited[v] = 1;

  for (int i = 0; i < 26; i++) 
  {
    if (g[v][i]) 
    {
      if (!visited[i])
        topological_sort(i);
      if (visited[i] == 1) 
      {
        cout << "Impossible\n";
        exit(0);
      }
    }
  }
  visited[v] = 2; // this is important
  s.push(v);
}

int main() 
{

  int n;
  cin >> n;
  string words[100];

  for (int i = 0; i < n; i++)
    cin >> words[i];

  int l1, l2, flag;
  
  for (int i = 0; i < n; i++) 
  {
    for (int j = i + 1; j < n; j++) 
    {
      l1 = words[i].length();
      l2 = words[j].length();
      flag = 0;

      for (int k = 0; k < min(l1, l2); k++) 
      {
        if (words[i][k] != words[j][k])
        {
          g[words[i][k] - 97][words[j][k] - 97] = 1;
          flag = 1;
          break;
        }
      }

      if (flag == 0) 
      {
        if (l1 >= l2) 
        {
          cout << "Impossible\n";
          return 0;
        }
      }
    }
  }

  for (int i = 0; i < 26; i++) 
  {
    for (int j = 0; j < 26; j++) 
    {
      if (g[i][j] && g[j][i]) 
      {
        cout << "Impossible\n";
        return 0;
      }
    }
  }

  for (int i = 0; i < 26; i++) 
  {
    if (!visited[i])
      topological_sort(i);
  }

  while (!s.empty()) 
  {
    cout << char(s.top() + 97);
    s.pop();
  }

  return 0;
}