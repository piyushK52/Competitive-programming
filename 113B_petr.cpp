#include<bits/stdc++.h>
using namespace std;

int L,L1,L2;
char s[2002],s1[2002],s2[2002];
int dp1[2002][2002],dp2[2002][2002],dp[2002][2002];

int main()
{
	cin>>s>>s1>>s2;
	L=strlen(s);
	L1=strlen(s1);
	L2=strlen(s2);

	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	memset(dp,0,sizeof(dp));
	
	for(int i=L-1;i>=0;i--)         
		for(int j=L-1;j>=0;j--)
			if(s[i]==s[j]) 
				dp[i][j]=1+dp[i+1][j+1];
			else 
				dp[i][j]=0;
		
	for(int i=L-1;i>=0;i--)
		for(int j=L1-1;j>=0;j--)
			if(s[i]==s1[j]) 
				dp1[i][j]=1+dp1[i+1][j+1];
			else 
				dp1[i][j]=0;
		
	
	for(int i=L-1;i>=0;i--)
		for(int j=L2-1;j>=0;j--)
			if(s[i]==s2[j]) 
				dp2[i][j]=1+dp2[i+1][j+1];
			else 
				dp2[i][j]=0;
		
	
	int ans=0;
	for(int i=0;i<L;i++)
	{
		if(dp1[i][0]!=L1)   // when dp1 == l1, it implies that we have found out the string s1
			continue;
		int maxi=max(L1,L2)-1;  // we are checking from opposite direction, that is instead of checking i+j where j<N-i
								// wer are checking I-j where I-j>0 and I = i+N
								// this ensures that our string always ends with L2
		for(int j=0;j<i;j++)         // eliminates repeated strings
			maxi=max(maxi,dp[i][j]);
		for(int j=i+maxi;j<L;j++)
			if(dp1[i][0]==L1 && dp2[j-L2+1][0]==L2) 
				ans++;            // to avoid doublecount
		
	}
	cout<<ans<<endl;
}