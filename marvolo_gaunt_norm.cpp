#include<bits/stdc++.h>

using namespace std;

int n,p,q,r;
const long long inf = 0x3F3F3F3F3F3F3F3F;
long long a[100010];
long long maxa = -inf,maxb = -inf;
long long ans = -inf;

int main()
{
	cin >> n >> p >> q >> r;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		maxa = max(maxa,a[i] * p);
		maxb = max(maxb,maxa + a[i] * q);
		ans = max(ans,maxb + a[i] * r);
	}
	cout << ans;
	return 0;
}