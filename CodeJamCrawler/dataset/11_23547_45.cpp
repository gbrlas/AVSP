#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long long tests,s,n,minn,ss,q;
int main(){   
    freopen("D:/C-small-attempt0.in","r",stdin);
    freopen("C:/output.txt","w",stdout);
cin>>tests;long pp=0;
for (;tests;--tests)
{pp++;s=ss=q=0;cin>>n;minn=1000000000;
for (int i=1;i<=n;i++)
{cin>>q;s=s^q;ss+=q;minn=min(minn,q);}
cout<<"Case #"<<pp<<": ";if (s)cout<<"NO"<<endl;
else {cout<<ss-minn<<endl;};}
cin.get();cin.get();
return 0;}
