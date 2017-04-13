#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define M_PI        3.14159265358979323846
#define eps 1e-9
using namespace std;
long ts,tests,c,d,ar,p,v,ara[2000000],szz,flag;
double l,r,m,psc,q;
int main(){  
 freopen("C:/input.in","r",stdin);
freopen("C:/output.txt","w",stdout);
cin>>tests;
for (;tests;--tests)
{ts++;cout<<"Case #"<<ts<<": ";
cin>>c>>d;
vector <long> ar;
 
 for(int i=1;i<=c;i++)
 {cin>>p>>v;
  for (int j=1;j<=v;j++)
   ar.push_back(p);
   }
  
 sort(ar.begin(),ar.end());

szz=ar.size();
 for (int i=1;i<=ar.size();i++)
  ara[i]=ar[i-1];
//for (int i=1;i<=szz;i++)cout<<ara[i]<<" ";
 l=0;r=1000000000;
 while (r-l>0.000000001)
 {m=l+r;m/=2;
       psc=ara[1]-m;flag=0;
       for (int i=2;i<=szz;i++)
       { q=max(psc+d,ara[i]-m);
        if (q>ara[i]+m)flag=1;
        else psc=q;}
  if (flag)l=m; else r=m;
 }cout.precision(8);
 cout<<fixed<<r<<endl;
} 
cin.get();cin.get();
return 0;}


