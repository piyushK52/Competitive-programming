#include <bits/stdc++.h>
using namespace std;
const int N = 505;
bool dp[2][N][N];

int main()
{
	int n, k;
	cin >> n >> k;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int now = i % 2;
		int last = 1 - now;
		int c;
        cin>>c;
		for(int j = 0; j <= k; j++)
			for(int y = 0; y <= j; y++)
			{
				dp[now][j][y] = dp[last][j][y];
				if(j >= c)
				{
				    dp[now][j][y] |= dp[last][j - c][y];
				    if(y >= c)
    					dp[now][j][y] |= dp[last][j - c][y - c];
				}
			}
	}
	vector <int> res;
	for(int i = 0; i <= k; i++)
		if(dp[n % 2][k][i])
			res.push_back(i);
	cout << res.size() << endl;
	for(int c : res)
		cout << c << " ";
	cout << endl;
}