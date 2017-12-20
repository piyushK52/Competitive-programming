#include <iostream>
using namespace std;

int maximum=0;
int g[6][6];

int find_val(int* a)
{
   //(g23 + g32 + g15 + g51) + (g13 + g31 + g54 + g45) + (g15 + g51) + (g54 + g45) 
   //cout<<"finding value for the arrangement: "<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<endl;
   int t=g[a[1]][a[2]]+g[a[3]][a[4]]+g[a[2]][a[3]]+g[a[4]][a[5]]+g[a[3]][a[4]]+g[a[4]][a[5]]+(g[a[2]][a[1]]+g[a[4]][a[3]]+g[a[3]][a[2]]+g[a[5]][a[4]]+g[a[4]][a[3]]+g[a[5]][a[4]]);
   //cout<<"value found is: "<<t<<endl;
   return t;
}

//********** program to find all the permutations of string a
inline void swap(int* x,int* y)
{
    //cout<<"number being swapped are: "<<*x<<" and "<<*y<<endl;
    int temp=*x;
    *x=*y;
    *y=temp;
}
//**********************MEMBLOCK*********************
void permute_n_check(int* a,int l,int r)   // O(N*N!), N! combinations and N complexity to print them
{
    if(l==r)                        // here we generally print the final sequence
    {
        if(find_val(a)>maximum)
        maximum=find_val(a);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a+l,a+i);
            permute_n_check(a,l+1,r);
            swap(a+l,a+i);
        }
    }
}
//***************************************************
//**************** permutation code ended
int main()
{
    
    for(int i=1;i<6;i++)
    cin>>g[i][1]>>g[i][2]>>g[i][3]>>g[i][4]>>g[i][5];

    int a[]={0,1,2,3,4,5};

    permute_n_check(a,1,5);

    cout<<maximum;
    
}