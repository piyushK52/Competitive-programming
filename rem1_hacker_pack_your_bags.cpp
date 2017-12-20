#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
const int mod = 1e9+7;
typedef long long ll;
#define mp make_pair
#define pb push_back

vector<pair<int,int>> min_value[N];
vector<pair<int,pair<int,ll>>> a;
int main()
{
	int n,x,l,r,c;
	cin>>n>>x;

	for(int i=1;i<=n;i++)
	{
		cin>>l>>r>>c;
		a.pb({l,{r,c}}); // putting in a vector list
	}
	sort(a.begin(),a.end()); // sorting by starting index

	for(int i=0;i<n;i++)
	{
		int l = a[i].first ,r = a[i].second.first , c= a[i].second.second;
		int d = r-l+1 ; 
		min_value[d].pb({l,c}); // starting point and cost for duration 'd'
	}


	for(int i=0;i<N;i++)
	{
		for(int j=min_value[i].size()-2;j>=0;j--)
		{
            min_value[i][j].second=min(min_value[i][j].second,min_value[i][j+1].second);
            // if there's a case with higher starting point same duration and less cost then we take it
		}
	}


	ll res=1e18;
	for(int i=0;i<n;i++)
	{
		int curr_val = a[i].second.first - a[i].first +1;
		ll curr_cost = a[i].second.second;
		int need = x - curr_val;
		if(need<0 or min_value[need].size()==0)
			continue;

		// current interval is [l,r] we want to find that item present in min_value[need] with it's l' > r.

		// since min_value[need] is sorted wrt it's first element l' , we can use binary search.

		int curr_right = a[i].second.first;
		int low = 0 ,high = min_value[need].size()-1,ind=-1;
		while(low<=high)
		{
			int mid  = (low+high)/2;
			if(min_value[need][mid].first>curr_right)
			{
				ind=mid; // valid index , but we want left most
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		if(ind==-1)
		{
			continue;
		}
		else
		{
			res=min(res,curr_cost + min_value[need][ind].second);
		}
	}
	if(res==1e18)
		cout<<-1<<endl;
	else
		cout<<res<<endl;
	return 0;
}