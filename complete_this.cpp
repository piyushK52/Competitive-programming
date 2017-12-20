#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
#define MAX 312
int triangle[MAX + 1][MAX + 1];
vector<int> same;
map<int,int> s,ns;
int fact[312];

bool is_perfect_square(int n) {
  if (n < 0)
      return false;
  int root(round(sqrt(n)));
  return n == root * root;
}


void factorial()
{
    fact[0] = fact[1] = 1;

    for(int i=2;i<=310;i++)
    {
        fact[i] = (i * fact[i-1]) % MOD;
    }
}

void makeTriangle() {
    int i, j;

    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j])%MOD;
        }
    }
}

int C(int n, int r) {
    return triangle[n][r];
}

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    if(is_perfect_square(temp))
    {
          if(s.find(temp)==s.end())
          s[temp]=1;
          else
          s[temp]++;
    }
    else
    {
      if(ns.find(temp)==ns.end())
      ns[temp]=1;
      else
      ns[temp]++;
    }

  }
  //cout<<"here";
  int result;
  if(ns.size()>=s.size()-1)
  {
    result=C(n,s.size());
    for(auto a: s)
    result/=fact[a.second];
    for(auto a: ns)
    result/fact[a.second];
    cout<<result<<endl;
  }
  else
  cout<<"0"<<endl;
}