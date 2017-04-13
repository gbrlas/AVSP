#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define M_PI        3.14159265358979323846
#define eps 1e-9
using namespace std;
long n,tt,tests,i,j,s1[1000],s2[1000];
double ans[1000],s3[1000];
char ar[1000][1000];
int main(){  
 freopen("C:/input.in","r",stdin);
freopen("C:/output.txt","w",stdout);
cin>>tests;
for (;tests;--tests)
{tt++;
cout<<"Case #"<<tt<<":"<<endl;
cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
cin>>ar[i][j];

for(int i=1;i<=n;i++)
s1[i]=s2[i]=0;
for (int i=1;i<=n;i++)s3[i]=0;

 for (int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 {if (ar[i][j]=='0')s2[i]++;
  else if (ar[i][j]=='1'){s1[i]++;s2[i]++;};}
 
 for (int i=1;i<=n;i++)
 ans[i]=double(s1[i])/s2[i]*0.25;
 
 for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  {if (ar[i][j]=='0'){s3[i]+=double(s1[j]-1)/(s2[j]-1)/s2[i];}
   if (ar[i][j]=='1'){s3[i]+=double(s1[j])/(s2[j]-1)/s2[i];}
}   

 for (int i=1;i<=n;i++)
 ans[i]+=s3[i]/2;
 
 //for (int i=1;i<=n;i++)cout<<s3[i]<<" "<<endl;
 
 for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 if (ar[i][j]=='0'||ar[i][j]=='1')
  ans[i]+=s3[j]/4/s2[i];
 cout.precision(10);
 for (int i=1;i<=n;i++)cout<<fixed<<ans[i]<<endl;}
cin.get();cin.get();
return 0;}


