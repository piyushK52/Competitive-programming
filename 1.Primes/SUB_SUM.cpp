//You are given 'n' integers and you have to find the sum of all the integers that can be expressed as a sum of subset of this array
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005];
bool dp[1005][1000005]; //dp[i][j]=true means that you can make the sum j using first i elements.
int main()
{
    int n, i, sum, j, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i + 1]; //both of these were i instead of i+1
            sum += arr[i + 1];
        }

        sort(arr, arr + n);

        for (i = 0; i <= n; i++)
            dp[i][0] = true;

        for (j = 1; j <= sum; j++)
            dp[0][j] = false;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum; j++)
            {
                if (j < arr[i])
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
                }
            }
        }

        /*cout<<"Printing the table obtained: "<<endl;
        for(i=0;i<=n;i++)
        {
            cout<<endl;
            for(j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
        }*/

        int ans = 0;
        for (j = 0; j <= sum; j++)
            if (dp[n][j] == true)         //finding all the integers that can be expressed as subset sum and adding them up.
            {
                //cout<<j<<" can be formed using these"<<endl;
                ans += j;
            }

        //cout<<endl;
        cout << ans << endl;
    }
}