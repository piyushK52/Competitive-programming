#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<int> g[maxn];
long long d[2];
void dfs(int cur, int pr, int dd){
	d[dd]++;
	for(int nxt : g[cur]) if(nxt != pr) dfs(nxt, cur, dd ^ 1);
}
int main(){
	int n;
	cin>>n;
	for(int e = 0; e < n - 1; e++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1, 0);
	cout << d[1] * d[0] - n + 1 << endl;
	return 0;
}