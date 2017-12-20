#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n;
vector<long double> a;

bool check(long double slope)
{
    unordered_set<long double> st;
    for(long long i=1;i<=n;i++)
        st.insert(a[i]-slope*i); // returns Yo-1 if the point lies on the line
    if(st.size()==2) // if there are two Yo's (two parallel lines) than we return 1
        return 1;
    return 0;
}
int main()
{
    cin>>n;
    a.resize(n+1);
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    bool ans = check(a[2]-a[1]) || check(a[3]-a[2]) || check((a[3]-a[1])/2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    if(ans)
        cout<<"Yes";
    else
        cout<<"No";
}