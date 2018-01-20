#include <bits/stdc++.h>
using namespace  std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

typedef pair <int, int> pii;
const int N = 220 ;

vector <int> vc[N] ;
int a[2][N] , b , Ans ;
pii edge[N] ;

void dfs ( int x , int Y )
{
    for (int i=0; i<vc[x].size(); i++) 
    if (vc[x][i]!=Y) 
    {
        int u=vc[x][i];
        dfs (u, x);
        //db = max( b , a[0][u]+a[1][u] ) ;
        if ( a[0][x]<a[0][u]+1 ) 
        	a[1][x] = a[0][x] , a[0][x] = a[0][u]+1 ;
        else 
        	a[1][x] = max( a[1][x] , a[0][u]+1) ;
    }
    b = max ( b , a[0][x]+a[1][x] ) ;
}

int main ()
{
    int n; cin>> n;
    for ( int i=1 ; i<n ; i++ ) 
    	{ cin>>edge[i].fr>>edge[i].sc; vc[edge[i].fr].pb( edge[i].sc ) , vc[edge[i].sc].pb( edge[i].fr ); }
    for ( int i=1 ; i<n ; i++ ) 
    {
        b=0;
        dfs (edge[i].fr, edge[i].sc);
        int e = b; b=0;
        dfs (edge[i].sc, edge[i].fr);
        Ans = max( Ans , e*b ) ;
        memset (a, 0, sizeof a);
    }
    return cout << Ans << endl , 0 ;
}