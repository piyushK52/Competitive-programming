#include <bits/stdc++.h>
using namespace std;

int n, m, k, l;
bool mark[310][310];
vector <pair<int, int> > v;

void dfs(int x, int y) 
{
	mark[x][y] = true, l++;
	v.push_back({x, y});
	if (l == m * n)
		return;
	if (y + 1 <= m && !mark[x][y + 1]) dfs(x, y + 1);
	else 
	{
		if ((y - 1) && !mark[x][y - 1]) dfs(x, y - 1);
		else dfs(x + 1, y);
	}
}

int main() 
{
	cin >> n >> m >> k;
    dfs(1, 1);
    l = 0;
	for (int i = 1; i < k; i++)
        {
         cout << 2 << " " << v[l].first << " " << v[l].second << " " << v[l + 1].first << " " << v[l + 1].second << endl;
         l += 2;
        }
	cout << v.size() - 2 * k + 2 << " ";
	for (int i = l; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << " ";
	return 0;
}