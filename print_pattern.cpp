#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    for (int i = 0; i < 26; i++)
    {
        int cnt = 1;
        while ((cnt - 1) * cnt / 2 <= k) cnt++;
        --cnt;
        k -= cnt * (cnt - 1) / 2;
        for (int j = 0; j < cnt; j++) 
        cout<<char(97 + i);
    }
    return 0;
}