#include<bits/stdc++.h>
using namespace std;
int n,p,q,r ;
vector<long long> a(110000) ;
unordered_map<string,long long> umap;
long long ex(int i,int s){
    int j=0;
    long long include;
    if(s==3 && i<=n)
        return 0;
    if(i==n && s<3)
        return -0x3F3F3F3F3F3F3F3F;
    if(umap.find(to_string(i)+"|"+to_string(s))==umap.end()){
        if(s==0)j=p;if(s==1)j=q;if(s==2)j=r ;
        if(j==p)
            include= ex(i,s+1) + p*a[i];
        if(j==q)
            include= ex(i,s+1) + q*a[i];
        if(j==r)
            include= ex(i,s+1) + r*a[i];
        long long exclude=ex(i+1,s);
        umap[to_string(i)+"|"+to_string(s)]= max(include,exclude);}
    return  umap[to_string(i)+"|"+to_string(s)];
    
}

int main()
{
    cin>>n>>p>>q>>r ;
    for(int i=0;i<n;i++)
        cin>>a[i] ;
    long long h=ex(0,0);
    cout<<h<<endl;
    return 0;
}
