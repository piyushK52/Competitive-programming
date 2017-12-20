#include <bits/stdc++.h>
#define LL long long
#define mx 1000000000000000 //infinity
using namespace std;
LL n,cost[100005]= {0},dp[2][100005]= {0},sum=0;
string arr[2][100005];
int main()
{
    cin >> n;
    for (LL i=1; i<=n; i++) cin >> cost[i];
    for (long i=1; i<=n; i++)
    {
        cin >> arr[0][i];
        arr[1][i]=arr[0][i];
        reverse(arr[1][i].begin(),arr[1][i].end());
    }
    dp[1][1]=cost[1];
    for (LL i=2; i<=n; i++)
        for (LL k=0; k<2; k++)
        {
            dp[k][i]=mx;
            for (LL j=0; j<2; j++)
                if (arr[j][i-1]<=arr[k][i])
                    dp[k][i]=min(dp[k][i],dp[j][i-1]+k*cost[i]);
        }
    sum=min(dp[0][n],dp[1][n]);
    if(sum==mx)cout << -1 ;
    else cout << sum ;

}