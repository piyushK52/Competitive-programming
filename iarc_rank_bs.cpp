#include<bits/stdc++.h>
#define inf -9223372036854775
#define ll long long
#define MAXN 100010
using namespace std;
 
vector<int> v;
 
int binary_search(int x){
	int a = 0,b = v.size()-1;
	while(a <= b){
		int mid = (a+b)/2;
		
		if(v[mid] > x) a = mid+1;
		else b = mid-1;
	}
	
	return a;
}
 
int main(){
 int N; cin >> N;
 
 while(N--){
 	int x; cin >> x;
 int place = binary_search(x);
 
 cout << place+1 << "\n";
 
 v.insert(v.begin()+place,x);
	}
 
 return 0;
}