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
long ar[2000000];double spd;
long minn,ansp;
double ans,t;
int main(){  
 freopen("C:/A-large.in","r",stdin);
freopen("C:/output.txt","w",stdout);
cin>>tests;long tes=0;
for (;tests;--tests)
{cin>>x>>s>>r>>t>>n;tes++;
 for (int i=0;i<=x;i++)
 { ar[i]=0;}

 for (int i=0;i<n;i++)
 {cin>>q>>w>>e;
 for (int j=q;j<w;j++)ar[j]=e;}

 ans=0;
 vector <pair <long , long> > vec;
 for (int i=0;i<x;i++)
 {pair <long, long> pr=make_pair(ar[i],i);
 vec.push_back(pr);}
 sort(vec.begin(),vec.end());

 for (int i=0;i<x;i++)
 {
 
   double qw=1;
   spd=vec[i].first+s;if (t>0){qw-=(spd+r-s)*t;
   if (qw<=0){t-=1.0/(spd+r-s);ans+=1.0/(spd+r-s);}
   else {t=0;ans+=qw/spd+(1-qw)/(spd+r-s);}}
   else ans+=1.0/spd;
 }cout.precision(10);
 cout<<"Case #"<<tes<<": "<<fixed<<ans<<endl;}
  
		return 0;}