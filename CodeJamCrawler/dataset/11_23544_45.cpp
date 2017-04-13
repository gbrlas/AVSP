#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
char ch;
long n,q,pp,p[1000],last[10000],moves[1000],tp,fl,ans,tests;
int main(){   
   freopen("D:/A-small-attempt0.in","r",stdin);
    freopen("C:/output.txt","w",stdout);
cin>>tests;
for (;tests;--tests)
{cin>>n;pp++;ans=0;
last[1]=1;last[2]=1;
moves[1]=0;moves[2]=0;
for (int i=1;i<=n;i++)
{cin>>ch;cin>>q;
ch=='O'?tp=1:tp=2;
while (moves[tp]<abs(q-last[tp])){moves[1]++;moves[2]++;ans++;}
ans++;moves[3-tp]++;last[tp]=q;moves[tp]=0;} 
cout<<"Case #"<<pp<<": ";cout<<ans<<endl;}
cin.get();cin.get();
return 0;}
