#include<bits/stdc++.h>
#define ll long long
#define N 2000009
using namespace std;

int n,del,inc,numof[N]; ll sum[N];
int main(){
	cin>>n>>del>>inc;
	int i,j,f,p=del/inc,k;
    for (i=1; i<=n; i++)
    {
		cin>>j;
		numof[j]++; sum[j]+=j;
	}
	for (i=1; i<=2000000; i++)
		numof[i]+=numof[i-1]; sum[i]+=sum[i-1];
	
	ll ans=(ll)n*del;
    for (int gcd=2; gcd<=1000000; gcd++)
    {
		ll tmp=0;
        for (k=gcd; k<=1000000+gcd && tmp<ans; k+=gcd)
        {
			f=max(k-gcd+1,k-p);
			tmp+=((ll)(numof[k]-numof[f-1])*k-(sum[k]-sum[f-1]))*inc;
			tmp+=(ll)(numof[f-1]-numof[k-gcd])*del;
		}
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}

// Steps:
/* first assume that there is some optimal gcd for which we get the minimum cost. We then check in each interval
(k-gcd,k] (where k is a multiple of gcd) the numbers we have to increase or the numbers we have to delete. In the 
interval if the numbers are greater than a certain value than it is better to just increase them otherwise delete
them. For finding this value 'f' we use the boundary condition, (k-f)*y>x => f<k-(x/y) {when cost of increasing is
more than the cost of deletion} but since the lower limit is k-gcd+1 our range for 'f' becomes f<k-min(gcd-1,x/y)
or we can writer f=max(k-gcd+1,k-(x/y)). now for all the numbers [f,k] we increase them, and [k-gcd+1,f-1] we
decrease them. we repeat this process for every gcd.
time complexity:
summation(a/g1+a/g2+...)=summation(a(1/2+1/3+...))=O(aloga) => a is the max element
*/