#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int count=0;
	int n;
    vector<int> v;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int rem=0;
    for(int i=0;i<n;i++)
    {
        if(rem>=v[i])
		{rem-=v[i];count--;}
		else if (lower_bound (v.begin(), v.end(), 4-v[i])!=v.end()&&v[lower_bound (v.begin(), v.end(), 4-v[i])-v.begin()]==4-v[i]&&((lower_bound (v.begin(), v.end(), 4-v[i])-v.begin()>i&&v[i]!=2)||(v[lower_bound (v.begin(), v.end(), 4-v[i])-v.begin()+1]==2&&v[i]==2&&lower_bound (v.begin(), v.end(), 4-v[i])-v.begin()+1>i)))
        {
            int j,k=0;
			if(v[i]==2)
			k++;
			for( j=lower_bound (v.begin(), v.end(), 4-v[i])-v.begin()+k;j>i;j--)
            v[j]=v[j-1];
            i++;
        }
        else
        rem=4-v[i];
        count++;
    }
    cout<<count<<endl;
}
