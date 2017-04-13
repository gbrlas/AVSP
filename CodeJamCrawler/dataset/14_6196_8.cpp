#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
       long long A,B,K;
       cin>>A>>B>>K;
       int c=0;
       for(long long i=0;i<A;i++)
       {
           for(long long j=0;j<B;j++)
           {
               if((i&j)<K)
               {
                   c++;
               }
           }
       }
       cout<<"Case #"<<t<<": "<<c<<"\n";
    }

}
