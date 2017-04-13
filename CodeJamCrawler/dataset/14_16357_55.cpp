#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
   freopen("c1.in", "r", stdin);
   freopen("c2.out", "w", stdout);
   int t,t1;
   long double c,f,x,n,min_time;
   cin>>t;
   for(t1=1;t1<=t;++t1)
   {
       n=2;min_time=0.0;
       cin>>c>>f>>x;
       while(true)
       {
           if((c/n)+(x/(n+f))>=(x/n))
           {
               min_time+=x/n;
               break;
           }
           else
           {
               min_time+=c/n;
               n=n+f;
           }
       }
       cout<<"Case #"<<t1<<": ";
       printf("%.7lf",min_time);
       cout<<"\n";
    }
    return 0;

}
