#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);//selecting input file
    freopen("output.txt","w",stdout);// selection output file
    int test;
    cin>>test;
    int count=0;
    while( test-- )
    {
           count++;
           int n,k;
           cin>>n>>k;
           k++;
           n=pow(2,n);
           if ( k%n==0 )
           {
                cout<<"Case #"<<count<<": ON";
           }
           else 
           {
                cout<<"Case #"<<count<<": OFF";
           }
           cout<<endl;
    }
}
