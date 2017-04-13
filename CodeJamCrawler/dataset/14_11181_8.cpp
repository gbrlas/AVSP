#include<iostream>
using namespace std;
int main()
{
    int t;
    int a,b,k,count;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
     count=0;
     cin>>a>>b>>k;
     for(int i=0;i<a;i++)
     {
         for(int j=0;j<b;j++)
         {
             if((i&j)<k)
             count++;
         }
     }
     cout<<"Case #"<<m<<": "<<count<<"\n";
    }
    return 0;
}
