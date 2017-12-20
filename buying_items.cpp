#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, k, x;
    vector<int> v;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
    {
        cin >> x;
        if(x == 1)
            v.push_back(i);
    }
    long long final_ans, ans = 0;
    if(v.size() < m)
        cout << -1 << endl;
    else 
    {
        for(int i = 0; i < m; i++) 
        {
            if(i == 0)
                ans += v[i];
            else ans += (long long)(v[i] - v[i-1])*k*(i);
            
        }
        final_ans = ans;
        
        for(int i = m; i < v.size();i++) 
        {
            long long left_ptr, decrement, left_increment, right_increment;
            decrement = (long long)(v[i-1]-v[i-m])*k;
            left_increment = v[i-m+1]-v[i-m];
            right_increment = (long long)(v[i]-v[i-1])*(m-1)*k;
            ans = ans - decrement + left_increment + right_increment;
            final_ans = min(final_ans, ans);
        }
        
        cout << final_ans << endl;
    }
    
    return 0;
}