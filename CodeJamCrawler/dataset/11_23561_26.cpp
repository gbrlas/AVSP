#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define M_PI        3.14159265358979323846
#define eps 1e-9
using namespace std;
long tests,x,s,p,r,n,w,e,q;
long ar[1000],u[100000];double spd;
long minn,ansp;
double ans,t;
int main(){  
 freopen("C:/A-small-attempt0.in","r",stdin);
freopen("C:/output.txt","w",stdout);
cin>>tests;long tes=0;
for (;tests;--tests)
{cin>>x>>s>>r>>t>>n;tes++;
 for (int i=0;i<=x;i++)
 {u[i]=0;	 ar[i]=0;}

 for (int i=0;i<n;i++)
 {cin>>q>>w>>e;
 for (int j=q;j<w;j++)ar[j]=e;}

 ans=0;
 for (int i=0;i<x;i++)
 {minn=10000;ansp=0;
   for(int j=0;j<x;j++)if (u[j]==0&&ar[j]<minn)
   {minn=ar[j];ansp=j;}

   double qw=1;
   spd=ar[ansp]+s;if (t>0){qw-=(spd+r-s)*t;
   if (qw<=0){t-=1.0/(spd+r-s);ans+=1.0/(spd+r-s);}
   else {t=0;ans+=qw/spd+(1-qw)/(spd+r-s);}}
   else ans+=1.0/spd;u[ansp]=1;
 // cout<<ansp<<" "<<t<<" "<<ans<<endl;
 }cout.precision(10);
 cout<<"Case #"<<tes<<": "<<fixed<<ans<<endl;}
  
		return 0;}