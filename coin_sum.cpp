#include<bits/stdc++.h>
using namespace std;
int coins[10],in;
map<int,int> tab;
void give(int i,int amount,queue<int> a,bool insert)
{
    
    if(amount<0||i>=in)
    return;
    else if(insert==true)
    {
        a.push(coins[i]);
    }
    if(amount==0)
    {
       while(!a.empty())
       {
           cout<<a.front()<<", ";
           a.pop();
       }
       cout<<endl;
    }
    else
    {
       give(i,amount-coins[i],a,true);
       give(i+1,amount,a,false);
    }
}
int main()
{
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    int t;in=0;
    for(int i=0;i<n;i++)
    {
       cin>>t;
       if(tab.end()==tab.find(t))
       {
           tab[t]=1;
           coins[in++]=t;
       }
    }
    
    queue<int> a;
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;
    bool insert=false;
    give(0,amount,a,insert);
}