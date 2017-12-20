#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1 << 17;

int dp[maxN];
vector<int> g[maxN];

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    ll ans = -1ll;
    for (int v = 1; v <= n; v++) {
        dp[v] = 1;
        for (auto u : g[v]) {
            if (u < v) {
                dp[v] = max(dp[v], dp[u] + 1);
            }
        }
        //cout<<"dp["<<v<<"] is: "<<dp[v]<<" g["<<v<<"] is: "<<g[v].size()<<endl;
        ans = max(ans, dp[v] * (ll)g[v].size());
    }
    cout << ans << endl;
    return 0;
}