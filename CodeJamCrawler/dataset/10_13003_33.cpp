#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);//selecting input file
    freopen("output.txt","w",stdout);// selection output file
    unsigned long int test;
    cin>>test;
    unsigned long int count=0;
    while( test-- )
    {
           count++;
           unsigned long int n,k;
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
