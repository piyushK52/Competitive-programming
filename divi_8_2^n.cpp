#include<bits/stdc++.h>
using namespace std;
string s;

void solve(int i,int rem,string pass)
{
   int r=(s[i]-48)%8;
   if((10*rem+r)%8==0)
   {cout<<"YES"<<endl;cout<<pass+s[i]<<endl;exit(0);}
   if(r==0)
   {cout<<"YES"<<endl;cout<<s[i]<<endl;exit(0);}
   if(i+1<s.length())
   {solve(i+1,(10*rem+r)%8,pass+s[i]);solve(i+1,rem,pass);}
}

int main()
{
	cin>>s;
	string pass;
	solve(0,0,pass);
	cout<<"NO"<<endl;
}