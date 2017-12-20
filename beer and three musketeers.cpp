#include<bits/stdc++.h>
using namespace std;

const int inf = 100000005;
int degree[5005];
bool t[5005][5005];

int main() 
{
	int n, m;
	cin>>n>>m;
    for(int i = 0; i < m; ++i) 
    {
		int a, b;
		cin>>a>>b;
		t[a][b] = t[b][a] = true;
		degree[a]++;
		degree[b]++;
	}
	int result = inf;
	for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j) 
        {
			// we are O(n^2) times here
			if(t[i][j]) {
				// we are O(m) times here
                for(int k = j + 1; k <= n; ++k) 
                {
					// O(m * n) times here
					if(t[i][k] && t[j][k])
						result = min(result, degree[i]+degree[j]+degree[k]);
				}
			}
		}
    if(result == inf) 
    cout<<"-1"<<endl;
    else 
    cout<<result - 6<<endl;
	return 0;
}